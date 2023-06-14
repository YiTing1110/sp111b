#include <stdio.h>
#include <sqlite3.h>

int main() {
    sqlite3 *db;
    char *errmsg;

    // 創建或連接資料庫
    int rc = sqlite3_open("天光.db", &db);
    if (rc != SQLITE_OK) {
        printf("無法創建或連接到資料庫: %s\n", sqlite3_errmsg(db));
        return 1;
    }

    // 創建資料表
    char *createTableSQL = "CREATE TABLE 總帳 ("
                           "銷貨單號 CHAR(9), "
                           "客戶名稱 VARCHAR, "
                           "序 INT, "
                           "天光型號 VARCHAR, "
                           "採購單號 VARCHAR, "
                           "廠商 VARCHAR, "
                           "客戶型號 VARCHAR, "
                           "數量 FLOAT, "
                           "客戶單價 FLOAT, "
                           "廠商成本 FLOAT, "
                           "客戶金額 FLOAT, "
                           "請款備註 VARCHAR, "
                           "工程位置 VARCHAR, "
                           "工程備註 VARCHAR, "
                           "收款 DATE, "
                           "總成本 FLOAT, "
                           "利潤 INT, "
                           "利潤百分比 INT, "
                           "本月利潤 INT, "
                           "年利潤 INT, "
                           "總利潤 INT, "
                           "本月收入 INT, "
                           "年收入 INT, "
                           "總收入 INT);";
    rc = sqlite3_exec(db, createTableSQL, 0, 0, &errmsg);
    if (rc != SQLITE_OK) {
        printf("無法創建資料表: %s\n", errmsg);
        return 1;
    }

    // 關閉資料庫連接
    sqlite3_close(db);

    return 0;
}
