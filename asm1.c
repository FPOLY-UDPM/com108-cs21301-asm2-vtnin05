/******************************************************************************
 * Họ và tên: [VÕ TUYẾT NHƯ]
 * MSSV:      [PS48854]
 * Lớp:       [CS21302]
 *****************************************************************************/

// Tạo file asm2.c và hoàn thiện nội dung Assignment từ nội dung file asm1.c


// Danh sách các chức năng trong ASM1:
// 1. Chức năng số 1: Kiểm tra số nguyên
// 2. Chức năng số 2. Tìm Ước số chung và bội số chung của 2 số 
// 3. Chức năng số 3: Chương trình tính tiền cho quán Karaoke
// 4. Chức năng số 4: Tính tiền điện 
// 5. Chức năng số 5: Chức năng đổi tiền 
// 6. Chức năng số 6: Xây dựng chức năng tính lãi suất vay ngân hàng vay trả góp 
// 7. Chức năng số 7: Xây dựng chương trình vay tiền mua xe
// 8. Chức năng số 8: Sắp xếp thông tin sinh viên
// 9. Chức năng số 9: Xây dựng game FPOLY-LOTT
// 10. Chức năng số 10: Xây dựng chương trình tính toán phân số 
// Viết chương trình C thực hiện các chức năng trên

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

// --- KHAI BÁO CÁC HÀM ---
void menu();
void chucNang1(); void chucNang2(); void chucNang3(); void chucNang4(); void chucNang5();
void chucNang6(); void chucNang7(); void chucNang8(); void chucNang9(); void chucNang10();

int main() {
    int chon;
    srand(time(NULL)); // Dùng cho game Lott
    do {
        menu();
        printf("Mời bạn chọn chức năng (0-10): ");
        scanf("%d", &chon);
        switch(chon) {
            case 1: chucNang1(); break;
            case 2: chucNang2(); break;
            case 3: chucNang3(); break;
            case 4: chucNang4(); break;
            case 5: chucNang5(); break;
            case 6: chucNang6(); break;
            case 7: chucNang7(); break;
            case 8: chucNang8(); break;
            case 9: chucNang9(); break;
            case 10: chucNang10(); break;
            case 0: printf("Cảm ơn bạn đã sử dụng chương trình!\n"); break;
            default: printf("Lựa chọn không hợp lệ!\n");
        }
    } while (chon != 0);
    return 0;
}

void menu() {
    printf("\n========= MENU CHƯƠNG TRÌNH =========\n");
    printf("1. Kiểm tra số nguyên\n2. Tìm ƯSC và BSC\n3. Tính tiền Karaoke\n");
    printf("4. Tính tiền điện\n5. Đổi tiền\n6. Lãi suất vay trả góp\n");
    printf("7. Vay tiền mua xe\n8. Sắp xếp sinh viên\n9. Game FPOLY-LOTT\n");
    printf("10. Tính toán phân số\n0. Thoát\n");
    printf("=====================================\n");
}

// 1. Kiểm tra số nguyên, nguyên tố, chính phương
void chucNang1() {
    float x;
    printf("Nhập x: ");
    scanf("%f", &x);
    if (x == (int)x) {
        int n = (int)x; printf("%.0f là số nguyên.\n", x);
        int c = 0;
        for (int i = 2; i <= sqrt(n); i++) if (n % i == 0) c++;
        if (n >= 2 && c == 0) printf("%d là số nguyên tố.\n", n);
        else printf("%d không là số nguyên tố.\n", n);
        if (sqrt(n) == (int)sqrt(n)) printf("%d là số chính phương.\n", n);
        else printf("%d không là số chính phương.\n", n);
    } else printf("%.2f không phải số nguyên.\n", x);
}

// 2. Ước số chung lớn nhất và Bội số chung nhỏ nhất
void chucNang2() {
    int x, y;
    printf("Nhập x, y: ");
    scanf("%d %d", &x, &y);
    int a = abs(x), b = abs(y);
    if (a == 0 || b == 0) printf("ƯCLN: %d\n", a + b);
    else {
        while (a != b) { if (a > b) a -= b; else b -= a; }
        printf("ƯCLN: %d\nBCNN: %d\n", a, abs(x * y) / a);
    }
}

// 3. Tính tiền Karaoke
void chucNang3() {
    int batDau, ketThuc;
    printf("Giờ bắt đầu và kết thúc (12-23h): "); scanf("%d %d", &batDau, &ketThuc);
    if (batDau < 12 || ketThuc > 23 || batDau >= ketThuc) return;
    int gio = ketThuc - batDau;
    double tien = (gio <= 3) ? (gio * 150000) : (3 * 150000 + (gio - 3) * 150000 * 0.7);
    if (batDau >= 14 && batDau <= 17) tien *= 0.9;
    printf("Tổng tiền: %.0f VNĐ\n", tien);
}

// 4. Tính tiền điện (6 bậc)
void chucNang4() {
    float kwh; double tien = 0;
    printf("Nhập số kWh: "); scanf("%f", &kwh);
    if (kwh <= 50) tien = kwh * 1678;
    else if (kwh <= 100) tien = 50 * 1678 + (kwh - 50) * 1734;
    else if (kwh <= 200) tien = 50 * 1678 + 50 * 1734 + (kwh - 100) * 2014;
    else if (kwh <= 300) tien = 82300 + 100 * 2014 + (kwh - 200) * 2536; // 82300 = 50*1678 + 50*1734
    else if (kwh <= 400) tien = 283700 + 100 * 2536 + (kwh - 300) * 2834;
    else tien = 537300 + 100 * 2834 + (kwh - 400) * 2927;
    printf("Tiền điện: %.0f VNĐ\n", tien);
}

// 5. Đổi tiền
void chucNang5() {
    int m[] = {500, 200, 100, 50, 20, 10, 5, 2, 1}, tien;
    printf("Nhập số tiền: ");
    scanf("%d", &tien);
    for (int i = 0; i < 9; i++) {
        if (tien / m[i] > 0) {
            printf("%d tờ mệnh giá %d\n", tien / m[i], m[i]); tien %= m[i]; }
    }
}

// 6. Lãi suất vay trả góp (12 tháng, lãi 5%/tháng)
void chucNang6() {
    double vay;
    printf("Số tiền vay: ");
    scanf("%lf", &vay);
    double goc = vay / 12;
    printf("Kỳ hạn | Lãi phải trả | Gốc phải trả | Tổng trả | Còn lại\n");
    for (int i = 1; i <= 12; i++) {
        double lai = vay * 0.05;
        printf("%6d | %12.0f | %12.0f | %8.0f | %8.0f\n", i, lai, goc, lai + goc, vay - goc);
        vay -= goc;
    }
}

// 7. Vay tiền mua xe (500tr, 24 năm, lãi 7.2%/năm)
void chucNang7() {
    float phanTram;
    printf("Phần trăm vay (ví dụ 80): ");
    scanf("%f", &phanTram);
    double giaXe = 500000000; // 500 triệu
    double soVay = giaXe * (phanTram / 100);
    printf("Số tiền trả lần đầu: %.0f VNĐ\n", giaXe - soVay);
    printf("Tiền trả hàng tháng (gốc): %.0f VNĐ\n", soVay / (24 * 12));
}

// 8. Sắp xếp sinh viên (Điểm giảm dần)
void chucNang8() {
    int n;
    printf("Số lượng SV: ");
    scanf("%d", &n);
    char ten[n][50]; float diem[n];
    for (int i = 0; i < n; i++) {
        printf("SV %d (Tên Điểm): ", i + 1);
        scanf("%s %f", ten[i], &diem[i]); }
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (diem[i] < diem[j]) {
                float td = diem[i]; diem[i] = diem[j]; diem[j] = td;
                char tt[50]; strcpy(tt, ten[i]); strcpy(ten[i], ten[j]); strcpy(ten[j], tt);
            }
    for (int i = 0; i < n; i++) {
        char *hl = (diem[i] >= 9) ? "Xuất sắc" : (diem[i] >= 8) ? "Giỏi" : (diem[i] >= 6.5) ? "Khá" : (diem[i] >= 5) ? "Trung bình" : "Yếu";
        printf("%s - %.1f - %s\n", ten[i], diem[i], hl);
    }
}

// 9. Game FPOLY-LOTT
void chucNang9() {
    int a, b, r1 = rand() % 15 + 1, r2 = rand() % 15 + 1, trung = 0;
    printf("Chọn 2 số (1-15): ");
    scanf("%d %d", &a, &b);
    printf("Kết quả: %d - %d\n", r1, r2);
    if (a == r1 || a == r2) trung++;
    if (b == r1 || b == r2) trung++;
    if (trung == 2) printf("Giải NHẤT\n");
    else if (trung == 1) printf("Giải NHÌ\n");
    else printf("Chúc may mắn lần sau\n");
}

// 10. Tính toán phân số
void chucNang10() {
    int t1, m1, t2, m2;
    printf("PS1 (tử mẫu): ");
    scanf("%d %d", &t1, &m1);
    printf("PS2 (tử mẫu): ");
    scanf("%d %d", &t2, &m2);
    if (m1 == 0 || m2 == 0) return;
    printf("Tổng: %d/%d\n", t1 * m2 + t2 * m1, m1 * m2);
    printf("Tích: %d/%d\n", t1 * t2, m1 * m2);
}