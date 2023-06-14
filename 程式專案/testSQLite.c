#include <stdio.h>
#include <sqlite3.h>

int callback(void *data, int argc, char **argv, char **azColName) {
    for (int i = 0; i < argc; i++) {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    return 0;
}

int main() {
    sqlite3 *db;
    char *errmsg;

    // 創建或連接資料庫
    int rc = sqlite3_open("database.db", &db);
    if (rc != SQLITE_OK) {
        printf("無法創建或連接到資料庫: %s\n", sqlite3_errmsg(db));
        return 1;
    }

    // 創建資料表
    char *createTableSQL = "CREATE TABLE Customers (ID INT PRIMARY KEY, Name TEXT, Email TEXT);";
    rc = sqlite3_exec(db, createTableSQL, 0, 0, &errmsg);
    if (rc != SQLITE_OK) {
        printf("無法創建資料表: %s\n", errmsg);
        return 1;
    }

    // 插入資料
    char *insertDataSQL = "INSERT INTO Customers (ID, Name, Email) VALUES (1, 'John Doe', 'john@example.com');";
    rc = sqlite3_exec(db, insertDataSQL, 0, 0, &errmsg);
    if (rc != SQLITE_OK) {
        printf("無法插入資料: %s\n", errmsg);
        return 1;
    }

    // 執行查詢
    char *selectDataSQL = "SELECT * FROM Customers;";
    rc = sqlite3_exec(db, selectDataSQL, callback, 0, &errmsg);
    if (rc != SQLITE_OK) {
        printf("無法執行查詢: %s\n", errmsg);
        return 1;
    }

    // 關閉資料庫連接
    sqlite3_close(db);

    return 0;
}
