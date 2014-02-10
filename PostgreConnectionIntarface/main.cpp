#include <iostream>

#include <pqxx/pqxx>

int main(int argc, char **argv) {

	try
	{
		pqxx::connection conn("dbname=db1 user=nikolay");
		std::cout << "connected to db1" << std::endl;

		try
		{
			pqxx::work action(conn);
			action.exec("create table records (key varchar, data text)");
			action.commit();
			std::cerr << "table created" << std::endl;
		}
		catch(const std::exception &e)
		{
			std::cout << "Creating table error" << std::endl;
			std::cerr << e.what() << std::endl;
		}

		try
		{
			pqxx::work action(conn);
			action.exec("insert into records (key, data) values ('key2', 'data2')");
			action.commit();
			std::cout<< "inserted" << std::endl;
		}
		catch(const std::exception &e)
		{
			std::cout << "Inserting error" << std::endl;
			std::cerr << e.what() << std::endl;
		}

		try
		{
			pqxx::work action2(conn);
			pqxx::result res = action2.exec("select * from records");
			for(pqxx::result::const_iterator i = res.begin(); i != res.end(); ++i)
			{
				for( pqxx::result::const_fielditerator j = i->begin(); j != i->end(); ++j)
				{
					std::cout << j->name() << " = '" << j->c_str() << "'" << std::endl;
				}
			}
			std::cout << std::endl;
		}
		catch(...)
		{
			std::cerr << "select error" << std::endl;
		}
	}
	catch(pqxx::broken_connection)
	{
		std::cout << "connection error" << std::endl;
	}
  return 0;
}
