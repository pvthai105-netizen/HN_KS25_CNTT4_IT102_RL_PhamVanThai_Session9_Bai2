#include <stdio.h>
#include <string.h>

struct FlightTicket {
    char pnrCode[15];
    char passengerName[50];
    int ticketClass;
    float baggageWeight;
    float baggageFee;
};

int main(void) {
    struct FlightTicket danhSachVe[100];
    int soLuong = 0;
    int luaChon;
    int i, j;
    int viTri;
    int found;
    char pnrInput[15];

    do {
        printf("\n=== HE THONG BAN VE VA CHECK-IN MAY BAY ===\n");
        printf("1. Them ve may bay moi\n");
        printf("2. Hien thi danh sach ve\n");
        printf("3. Cap nhat hanh ly theo PNR\n");
        printf("4. Xoa ve theo PNR\n");
        printf("5. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &luaChon);

        switch (luaChon) {
            case 1:
                if (soLuong >= 100) {
                    printf("Danh sach ve da day, khong the them moi!\n");
                    break;
                }

                printf("\nNhap ma PNR: ");
                scanf("%14s", danhSachVe[soLuong].pnrCode);

                while (getchar() != '\n');

                printf("Nhap ho ten hanh khach: ");
                fgets(danhSachVe[soLuong].passengerName,
                      sizeof(danhSachVe[soLuong].passengerName), stdin);

                danhSachVe[soLuong].passengerName[
                    strcspn(danhSachVe[soLuong].passengerName, "\n")
                ] = '\0';

                printf("Nhap hang ve (1-Eco, 2-Deluxe, 3-Business): ");
                scanf("%d", &danhSachVe[soLuong].ticketClass);

                printf("Nhap khoi luong hanh ly (kg): ");
                scanf("%f", &danhSachVe[soLuong].baggageWeight);

                if (danhSachVe[soLuong].ticketClass == 3) {
                    danhSachVe[soLuong].baggageFee = 0.0f;
                } else if (danhSachVe[soLuong].baggageWeight <= 7.0f) {
                    danhSachVe[soLuong].baggageFee = 0.0f;
                } else {
                    danhSachVe[soLuong].baggageFee =
                        (danhSachVe[soLuong].baggageWeight - 7.0f) * 50000.0f;
                }

                printf("=> Them ve thanh cong! Cuoc phat hanh ly qua can: %.0f VND.\n",
                       danhSachVe[soLuong].baggageFee);

                soLuong++;
                break;

            case 2:
                if (soLuong == 0) {
                    printf("Danh sach ve dang rong!\n");
                    break;
                }

                printf("\n========================================================================================\n");
                printf("%-5s %-10s %-25s %-12s %-15s %-15s\n",
                       "STT", "Ma PNR", "Ho ten hanh khach",
                       "Hang ve", "Hanh ly (kg)", "Cuoc qua cuoc");
                printf("========================================================================================\n");

                for (i = 0; i < soLuong; i++) {
                    if (danhSachVe[i].ticketClass == 1) {
                        printf("%-5d %-10s %-25s %-12s %-15.1f %-15.0f VND\n",
                               i + 1,
                               danhSachVe[i].pnrCode,
                               danhSachVe[i].passengerName,
                               "Eco",
                               danhSachVe[i].baggageWeight,
                               danhSachVe[i].baggageFee);
                    } else if (danhSachVe[i].ticketClass == 2) {
                        printf("%-5d %-10s %-25s %-12s %-15.1f %-15.0f VND\n",
                               i + 1,
                               danhSachVe[i].pnrCode,
                               danhSachVe[i].passengerName,
                               "Deluxe",
                               danhSachVe[i].baggageWeight,
                               danhSachVe[i].baggageFee);
                    } else {
                        printf("%-5d %-10s %-25s %-12s %-15.1f %-15.0f VND\n",
                               i + 1,
                               danhSachVe[i].pnrCode,
                               danhSachVe[i].passengerName,
                               "Business",
                               danhSachVe[i].baggageWeight,
                               danhSachVe[i].baggageFee);
                    }
                }

                printf("========================================================================================\n");
                break;

            case 3:
                if (soLuong == 0) {
                    printf("Danh sach ve dang rong!\n");
                    break;
                }

                printf("\nNhap ma PNR can cap nhat hanh ly: ");
                scanf("%14s", pnrInput);

                found = 0;

                for (i = 0; i < soLuong; i++) {
                    if (strcmp(danhSachVe[i].pnrCode, pnrInput) == 0) {
                        found = 1;
                        viTri = i;
                        break;
                    }
                }

                if (found == 0) {
                    printf("Khong tim thay ve co ma PNR da nhap!\n");
                } else {
                    printf("Tim thay hanh khach: %s\n",
                           danhSachVe[viTri].passengerName);

                    printf("Nhap trong luong hanh ly moi (kg): ");
                    scanf("%f", &danhSachVe[viTri].baggageWeight);

                    if (danhSachVe[viTri].ticketClass == 3) {
                        danhSachVe[viTri].baggageFee = 0.0f;
                    } else if (danhSachVe[viTri].baggageWeight <= 7.0f) {
                        danhSachVe[viTri].baggageFee = 0.0f;
                    } else {
                        danhSachVe[viTri].baggageFee =
                            (danhSachVe[viTri].baggageWeight - 7.0f) * 50000.0f;
                    }

                    printf("=> Cap nhat thanh cong! Phi hanh ly qua cuoc moi: %.0f VND.\n",
                           danhSachVe[viTri].baggageFee);
                }
                break;

            case 4:
                if (soLuong == 0) {
                    printf("Danh sach ve dang rong!\n");
                    break;
                }

                printf("\nNhap ma PNR can xoa: ");
                scanf("%14s", pnrInput);

                found = 0;

                for (i = 0; i < soLuong; i++) {
                    if (strcmp(danhSachVe[i].pnrCode, pnrInput) == 0) {
                        found = 1;

                        for (j = i; j < soLuong - 1; j++) {
                            danhSachVe[j] = danhSachVe[j + 1];
                        }

                        soLuong--;

                        printf("=> Da xoa thanh cong ve co ma PNR: %s ra khoi he thong.\n",
                               pnrInput);
                        break;
                    }
                }

                if (found == 0) {
                    printf("Khong tim thay ve co ma PNR da nhap!\n");
                }
                break;

            case 5:
                printf("Cam on ban da su dung chuong trinh!\n");
                break;

            default:
                printf("Lua chon khong hop le! Vui long chon lai.\n");
        }

    } while (luaChon != 5);

    return 0;
}

