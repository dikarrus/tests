#ifndef DBINTERFACE_H
#define DBINTERFACE_H

#include <string>

/** 
 * Класс предоставляет интерфейс к БД PostgreSQL
 * Интерфейсные методы:
 * Получение данных (select) --> throws ...
 * Добавление строки (insert) --> throws ...
 * Обновление строки (update) --> throws ...
**/ 

class PgInterface
{
public:
  explicit PgInterface(std::string host,
    std::string user,
    std::string pass,
    std::string dbname);

  void getTextByKey
  
private:
  pqxx::connection m_connection;
  pqxx::work       *action;
}

#endif DBINTERFACE_H