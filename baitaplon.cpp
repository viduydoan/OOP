#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <algorithm>

using namespace std;

class MonAn {
private:
    string tenMon;
    string loaiMon;
    double giaTien;

public:
    MonAn(string ten, string loai, double gia) : tenMon(ten), loaiMon(loai), giaTien(gia) {}

    string getTenMon() const { return tenMon; }
    string getLoaiMon() const { return loaiMon; }
    double getGiaTien() const { return giaTien; }

    void hienThiMonAn() const {
        cout << tenMon << " (" << loaiMon << ") - " << giaTien << " VND" << endl;
    }
};

class KhachHang {
private:
    string maKH;
    string tenKH;
    int diemTichLuy;

public:
    KhachHang(string ma, string ten) : maKH(ma), tenKH(ten), diemTichLuy(0) {}

    string getMaKH() const { return maKH; }
    string getTenKH() const { return tenKH; }
    int getDiemTichLuy() const { return diemTichLuy; }

    void themDiem(int diem) { diemTichLuy += diem; }
    void hienThiThongTin() const {
        cout << "Ma KH: " << maKH << " - Ten: " << tenKH << " - Diem tich luy: " << diemTichLuy << endl;
    }
};

class HoaDon {
private:
    int soHoaDon;
    string maKH;
    double tongTien;

public:
    HoaDon(int so, string maKH, double tien) : soHoaDon(so), maKH(maKH), tongTien(tien) {}

    double getTongTien() const { return tongTien; }

    void hienThiHoaDon() const {
        cout << "So hoa don: " << soHoaDon << " - Ma KH: " << maKH << " - Tong tien: " << tongTien << " VND" << endl;
    }
};

class NhaHang {
private:
    vector<MonAn> menu;
    vector<KhachHang> danhSachKhachHang;
    vector<HoaDon> danhSachHoaDon;
    double doanhThu;

public:
    NhaHang() : doanhThu(0) {}

    string chuanHoaTen(const string& ten) const {
        string result = ten;
        transform(result.begin(), result.end(), result.begin(), ::tolower);
        return result;
    }

    bool kiemTraMonAnTrung(const string& tenMon) const {
        string tenMonLower = chuanHoaTen(tenMon);
        for (size_t i = 0; i < menu.size(); ++i) {
            if (chuanHoaTen(menu[i].getTenMon()) == tenMonLower) {
                return true;
            }
        }
        return false;
    }

    void themMonAnVaoMenu(const MonAn &mon) {
        if (kiemTraMonAnTrung(mon.getTenMon())) {
            cout << "Mon an '" << mon.getTenMon() << "' da ton tai trong menu!" << endl;
        } else {
            menu.push_back(mon);
            cout << "Da them mon an vao menu." << endl;
        }
    }

    void hienThiMenu() const {
        if (menu.empty()) {
            cout << "Menu hien tai dang trong!" << endl;
        } else {
            for (size_t i = 0; i < menu.size(); ++i) {
                cout << i + 1 << ". ";
                menu[i].hienThiMonAn();
            }
        }
    }

    bool kiemTraKhachHangTrung(const string& tenKH) const {
        string tenKHLower = chuanHoaTen(tenKH);
        for (size_t i = 0; i < danhSachKhachHang.size(); ++i) {
            if (chuanHoaTen(danhSachKhachHang[i].getTenKH()) == tenKHLower) {
                return true;
            }
        }
        return false;
    }

    void themKhachHang(const KhachHang &kh) {
        if (kiemTraKhachHangTrung(kh.getTenKH())) {
            cout << "Khach hang '" << kh.getTenKH() << "' da ton tai! Khong the them." << endl;
        } else {
            danhSachKhachHang.push_back(kh);
            cout << "Da them khach hang moi." << endl;
        }
    }

    void hienThiDanhSachKhachHang() const {
        if (danhSachKhachHang.empty()) {
            cout << "Danh sach khach hang trong!" << endl;
        } else {
            for (size_t i = 0; i < danhSachKhachHang.size(); ++i) {
                danhSachKhachHang[i].hienThiThongTin();
            }
        }
    }

    void themDiemTichLuyChoKH(const string &maKH, int diem) {
        for (size_t i = 0; i < danhSachKhachHang.size(); ++i) {
            if (danhSachKhachHang[i].getMaKH() == maKH) {
                danhSachKhachHang[i].themDiem(diem);
                cout << "Da them " << diem << " diem cho khach hang " << maKH << endl;
                return;
            }
        }
        cout << "Khong tim thay khach hang voi ma " << maKH << endl;
    }

    void themHoaDon(const HoaDon &hd) {
        danhSachHoaDon.push_back(hd);
        doanhThu += hd.getTongTien();
    }

    void hienThiDoanhThu() const {
        cout << "Tong doanh thu: " << doanhThu << " VND" << endl;
    }

    void hienThiDanhSachHoaDon() const {
        if (danhSachHoaDon.empty()) {
            cout << "Chua co hoa don nao!" << endl;
        } else {
            for (size_t i = 0; i < danhSachHoaDon.size(); ++i) {
                danhSachHoaDon[i].hienThiHoaDon();
            }
        }
    }
};

void hienThiMenuLuaChon() {
    cout << "\n--- Quan ly nha hang ---" << endl;
    cout << "1. Hien thi menu" << endl;
    cout << "2. Them mon an vao menu" << endl;
    cout << "3. Them khach hang moi" << endl;
    cout << "4. Hien thi danh sach khach hang" << endl;
    cout << "5. Them diem tich luy cho khach hang" << endl;
    cout << "6. Them hoa don" << endl;
    cout << "7. Hien thi danh sach hoa don" << endl;
    cout << "8. Hien thi doanh thu" << endl;
    cout << "9. Thoat" << endl;
}

void xoaManHinh() {  
        system("cls");         
    
}

int main() {
    NhaHang nhaHang;
    int luaChon;

    do {
        xoaManHinh();
        hienThiMenuLuaChon();
        cout << "Nhap lua chon: ";
        cin >> luaChon;

        xoaManHinh();

        switch (luaChon) {
        case 1:
            nhaHang.hienThiMenu();
            break;
        case 2: {
            string tenMon, loaiMon;
            double gia;
            cout << "Nhap ten mon: ";
            cin.ignore();
            getline(cin, tenMon);
            if (nhaHang.kiemTraMonAnTrung(tenMon)) {
                cout << "Mon an '" << tenMon << "' da ton tai! Khong the nhap thong tin cho mon an." << endl;
                break;
            }
            cout << "Nhap loai mon: ";
            getline(cin, loaiMon);
            cout << "Nhap gia tien: ";
            cin >> gia;
            nhaHang.themMonAnVaoMenu(MonAn(tenMon, loaiMon, gia));
            break;
        }
        case 3: {
            string maKH, tenKH;
            cout << "Nhap ma khach hang: ";
            cin >> maKH;
            cout << "Nhap ten khach hang: ";
            cin.ignore();
            getline(cin, tenKH);
            if (nhaHang.kiemTraKhachHangTrung(tenKH)) {
                cout << "Khach hang '" << tenKH << "' da ton tai! Khong the nhap thong tin cho khach hang." << endl;
                break;
            }
            nhaHang.themKhachHang(KhachHang(maKH, tenKH));
            break;
        }
        case 4:
            nhaHang.hienThiDanhSachKhachHang();
            break;
        case 5: {
            string maKH;
            int diem;
            cout << "Nhap ma khach hang: ";
            cin >> maKH;
            cout << "Nhap diem tich luy muon them: ";
            cin >> diem;
            nhaHang.themDiemTichLuyChoKH(maKH, diem);
            break;
        }
        case 6: {
            int soHD;
            string maKH;
            double tongTien;
            cout << "Nhap so hoa don: ";
            cin >> soHD;
            cout << "Nhap ma khach hang: ";
            cin >> maKH;
            cout << "Nhap tong tien: ";
            cin >> tongTien;
            nhaHang.themHoaDon(HoaDon(soHD, maKH, tongTien));
            break;
        }
        case 7:
            nhaHang.hienThiDanhSachHoaDon();
            break;
        case 8:
            nhaHang.hienThiDoanhThu();
            break;
        case 9:
            cout << "Thoat chuong trinh." << endl;
            break;
        default:
            cout << "Lua chon khong hop le! Vui long chon lai." << endl;
            break;
        }

        cout << "Nhap phim bat ky de tiep tuc...";
        cin.ignore();
        cin.get();
    } while (luaChon != 9);

    return 0;
}

