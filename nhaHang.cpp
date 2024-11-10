﻿#pragma once
#include"nhahang.h"



bool isDigit(char c) {
    return c >= '0' && c <= '9';
}
bool isNumber(const string& s) {
    for (char c : s) {
        if (!isDigit(c)) return false;
    }
    return !s.empty();
}

bool isValidPhoneNumber(const string& phoneNumber) {
    if (phoneNumber.length() < 10 || phoneNumber.length() > 11) return false;
    for (char c : phoneNumber) {
        if (!isDigit(c)) return false;
    }
    return true;
}

bool isValidName(const string& name) {
    return !name.empty();
}

int nhapSo(const string& prompt) {
    string input;
    while (true) {
        cout << BLUE_COLOR << prompt << RESET_COLOR;
        cin >> input;
        if (isNumber(input)) {
            cin.ignore();
            return stoi(input);
        }
        else {
            cout << BLUE_COLOR << "Loi: Vui long nhap mot so hop le!" << RESET_COLOR << endl;
        }
    }
}

bool isLetter(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

bool isAllLetters(const string& s) {
    for (char c : s) {
        if (!isLetter(c)) return false;
    }
    return !s.empty();
}
const string BLUE_COLOR = "\033[1;34m";
const string RESET_COLOR = "\033[0m";
const string RED_COLOR = "\033[31m";


KhachHang::KhachHang(string ma, string tenKH) : sdt(ma), ten(tenKH), diemTichLuy(0), soLanVaoNhaHang(0) {}

string KhachHang::getSdt() const { return sdt; }
string KhachHang::getTen() const { return ten; }
int KhachHang::getDiemTichLuy() const { return diemTichLuy; }

void KhachHang::tichDiem() {
    soLanVaoNhaHang++;
    diemTichLuy += 10;
}

double KhachHang::quyDoiDiem() {
    double voucher = diemTichLuy * 200;
    diemTichLuy = 0;
    return voucher;
}

void KhachHang::hienThiThongTin() const {
    cout << BLUE_COLOR << "Hoi vien: " << ten << " - sdt: " << sdt << " - Diem tich luy: " << diemTichLuy << "- So lan ghe: " << soLanVaoNhaHang << RESET_COLOR << endl;
}

BanAn::BanAn(int so) : soBan(so), tongTien(0), daDuocDat(false) {}

bool BanAn::getDaDuocDat() const {
    return daDuocDat;
}


void BanAn::datBan() {
    daDuocDat = true;
}



int BanAn::getSoBan() const { return soBan; }

void BanAn::themMonAn(const MonAn& mon) {
    danhSachMonAn.push_back(mon);
    tongTien += mon.getGiaTien();
}


double BanAn::getTongTien() const { return tongTien; }

double BanAn::getChiPhi() const {
    double tongChiPhi = 0.0;
    for (const auto& monAn : danhSachMonAn) {
        tongChiPhi += monAn.getChiPhi();
    }
    return tongChiPhi;
}

void BanAn::thanhToan() {
    time_t now = time(0);
    tm ltm;  
    localtime_s(&ltm, &now);

    cout << BLUE_COLOR;
    cout << "+----------------------------NHA HANG VIP-------------------------------+" << endl;
    cout << "|                                                                       |" << endl;
    cout << "| Dia chi: 450 - 451, duong Le Van Viet, phuong Tang Nhon Phu A, Quan 9 |" << endl;
    cout << "| SDT: 0378423758                                                       |" << endl;
    cout << "| Ban " << setw(3) << soBan << "                         HOA DON                               |" << endl;

    cout << "| Ngay gio: ";
    cout << 1900 + ltm.tm_year << "-";
    cout << (1 + ltm.tm_mon < 10 ? "0" : "") << 1 + ltm.tm_mon << "-";
    cout << (ltm.tm_mday < 10 ? "0" : "") << ltm.tm_mday << " ";
    cout << (ltm.tm_hour < 10 ? "0" : "") << ltm.tm_hour << ":";
    cout << (ltm.tm_min < 10 ? "0" : "") << ltm.tm_min << ":";
    cout << (ltm.tm_sec < 10 ? "0" : "") << ltm.tm_sec;
    cout << "                                         |" << endl;

    cout << "| Nhan Vien: Vi Duy Doan                                                |" << endl;
    cout << "| " << setw(3) << "Ma" << setw(15) << "Ten Mon" << setw(15) << "Loai" << setw(10) << "Gia" << "                           |" << endl;
    cout << "+-----------------------------------------------------------------------+" << endl;
    cout << RESET_COLOR;


    for (const MonAn& mon : danhSachMonAn) {
        cout << BLUE_COLOR << "| " << RESET_COLOR;
        mon.hienThiMonAn3();
        cout << BLUE_COLOR << "                        |" << RESET_COLOR << endl;
    }

    cout << BLUE_COLOR;
    cout << "+-----------------------------------------------------------------------+" << endl;
    cout << "| Tong tien:                       " << setw(10) << tongTien << "VND                        |" << endl;
    cout << "+-----------------------------------------------------------------------+" << endl;
    cout << RESET_COLOR;


    danhSachMonAn.clear();
    tongTien = 0;
    daDuocDat = false;
}

string MonAn::getMaMon() const { return maMon; }
string MonAn::getTenMon() const { return tenMon; }
string MonAn::getLoaiMon() const { return loaiMon; }
double MonAn::getGiaTien() const { return giaTien; }
double MonAn::getChiPhi() const { return chiPhi; }

void MonAn::hienThiMonAn() const {
    cout << BLUE_COLOR << maMon << ": " << tenMon << " (" << loaiMon << ") - "
        << "Gia: " << giaTien << " VND " << RESET_COLOR << endl;
}
void MonAn::hienThiMonAn2() const {

    cout << BLUE_COLOR
        << left << setw(3) << maMon
        << left << setw(15) << tenMon
        << left << setw(15) << loaiMon
        << left << setw(10) << giaTien
        << "VND" << RESET_COLOR << endl;
}

void MonAn::hienThiMonAn3() const {

    cout << BLUE_COLOR
        << left << setw(3) << maMon
        << left << setw(15) << tenMon
        << left << setw(15) << loaiMon
        << left << setw(10) << giaTien
        << "VND" << RESET_COLOR;
}




void NhaHang::datBan(int soBan) {
    BanAn* ban = timBanAn(soBan);
    if (ban) {
        if (ban->getDaDuocDat()) {
            cout << BLUE_COLOR << "Ban so " << soBan << " da duoc dat roi!" << RESET_COLOR << endl;
        }
        else {
            ban->datBan();
            cout << BLUE_COLOR << "Ban so " << soBan << " da duoc dat thanh cong!" << RESET_COLOR << endl;
        }
    }
    else {
        cout << BLUE_COLOR << "Khong tim thay ban an so " << soBan << RESET_COLOR << endl;
    }
}



NhaHang::NhaHang() : doanhThu(0), chiPhi(0.0) {}


void NhaHang::themBanAn(int soBan) {
    danhSachBanAn.push_back(BanAn(soBan));
    cout << BLUE_COLOR << "Da them ban so " << soBan << RESET_COLOR << endl;
}

BanAn* NhaHang::timBanAn(int soBan) {
    for (auto& ban : danhSachBanAn) {
        if (ban.getSoBan() == soBan) {
            return &ban;
        }
    }
    return nullptr;
}

void NhaHang::hienThiDanhSachHoiVien() const {
    cout << BLUE_COLOR << "=======================================\n" << RESET_COLOR;
    cout << BLUE_COLOR << "|           Danh sach hoi vien        |\n" << RESET_COLOR;
    cout << BLUE_COLOR << "=======================================\n" << RESET_COLOR;
    for (const KhachHang& kh : danhSachHoiVien) {
        kh.hienThiThongTin();
    }
    cout << BLUE_COLOR << "=======================================\n" << RESET_COLOR;
}



void NhaHang::hienThiMenu() const {
    cout << BLUE_COLOR << "=======================================\n" << RESET_COLOR;
    cout << BLUE_COLOR << "|                MENU                 |\n" << RESET_COLOR;
    cout << BLUE_COLOR << "=======================================\n" << RESET_COLOR;
    for (const MonAn& mon : menu) {
        cout << BLUE_COLOR << "| " << RESET_COLOR;

        mon.hienThiMonAn();

    }
    cout << BLUE_COLOR << "=======================================\n" << RESET_COLOR;
}

void NhaHang::hienThiMenu2() const {
    cout << BLUE_COLOR << "=======================================\n" << RESET_COLOR;
    cout << BLUE_COLOR << "|                 MENU                |\n" << RESET_COLOR;
    cout << BLUE_COLOR << "=======================================\n" << RESET_COLOR;
    cout << BLUE_COLOR << "|Ma   Ten Mon          Loai          Gia" << RESET_COLOR << endl;
    cout << BLUE_COLOR << "|" << RESET_COLOR << endl;
    for (const MonAn& mon : menu) {
        cout << BLUE_COLOR << "| " << RESET_COLOR;

        mon.hienThiMonAn2();

    }
    cout << BLUE_COLOR << "========================================\n" << RESET_COLOR;
}

void NhaHang::themMonAnVaoMenu(const MonAn& mon) {
    menu.push_back(mon);

}


bool NhaHang::kiemTraMonAnTonTai(const MonAn& mon) const {
    for (const MonAn& m : menu) {
        if (m.getMaMon() == mon.getMaMon() || m.getTenMon() == mon.getTenMon()) {
            return true;
        }
    }
    return false;
}

void NhaHang::goiMon(int soBan, const std::vector<int>& danhSachMaMon) {
    BanAn* ban = timBanAn(soBan);
    if (ban) {
        if (!ban->getDaDuocDat()) {
            cout << BLUE_COLOR << "Ban so " << soBan << " chua duoc dat. Vui long dat ban truoc khi goi mon!" << RESET_COLOR << endl;
            return;
        }

        for (int maMon : danhSachMaMon) {
            bool monDaTimThay = false;

            for (const MonAn& mon : menu) {
                if (stoi(mon.getMaMon()) == maMon) {
                    ban->themMonAn(mon);
                    chiPhi += mon.getChiPhi();
                    cout << BLUE_COLOR << "Da goi mon '" << mon.getTenMon() << "' cho ban so " << soBan << RESET_COLOR << endl;
                    monDaTimThay = true;
                    break;
                }
            }

            if (!monDaTimThay) {
                cout << BLUE_COLOR << "Khong tim thay mon an voi ma '" << maMon << "'" << RESET_COLOR << endl;
            }
        }
    }
    else {
        cout << BLUE_COLOR << "Khong tim thay ban an so " << soBan << RESET_COLOR << endl;
    }
}




void NhaHang::hienThiBanTrong() const {
    cout << BLUE_COLOR << "+----------------------------------------+" << endl;
    cout << "|       D A N H   S A C H   C A C        |" << endl;
    cout << "|       B A N   T R O N G                |" << endl;
    cout << "+----------------------------------------+" << endl;

    int maxCot = 5;
    int soCot = 0;

    for (const BanAn& ban : danhSachBanAn) {
        if (ban.getDaDuocDat() == false) {
            if (soCot == maxCot) {
                cout << endl;
                soCot = 0;
            }


            cout << RED_COLOR << "|  Ban " << ban.getSoBan() << "  " << RESET_COLOR;
        }
        else {
            if (soCot == maxCot) {
                cout << endl;
                soCot = 0;
            }


            cout << "|  Ban " << ban.getSoBan() << "  ";
        }

        soCot++;
    }


    if (soCot > 0) {
        cout << "+" << endl;
    }

    cout << BLUE_COLOR << "======================================\n" << RESET_COLOR;
}


void NhaHang::thanhToanBan(int soBan) {
    BanAn* ban = timBanAn(soBan);
    if (ban) {
        string tenKhachHang;
        cout << BLUE_COLOR << "Ban co phai la hoi vien khong? (y/n): " << RESET_COLOR;
        char hoiVien;
        cin >> hoiVien;

        double tongTien = ban->getTongTien();
        double chiPhi = ban->getChiPhi();

        if (hoiVien == 'y' || hoiVien == 'Y') {
            cout << BLUE_COLOR << "Nhap so dien thoai hoi vien: " << RESET_COLOR;
            string soDienThoai;
            cin >> soDienThoai;

            if (!isValidPhoneNumber(soDienThoai)) {
                cout << BLUE_COLOR << "So dien thoai khong hop le. Vui long nhap lai!" << RESET_COLOR << endl;
                return;
            }

            KhachHang* khachHang = timHoiVien(soDienThoai);

            if (khachHang) {
                khachHang->tichDiem();
                cout << BLUE_COLOR << "Da them diem tich luy cho hoi vien voi so dien thoai " << soDienThoai << RESET_COLOR << endl;

                cout << BLUE_COLOR << "Ban co muon quy doi voucher khong? (y/n): " << RESET_COLOR;
                char quyDoi;
                cin >> quyDoi;

                if (quyDoi == 'y' || quyDoi == 'Y') {
                    double voucher = khachHang->quyDoiDiem();
                    cout << BLUE_COLOR << "Da quy doi " << voucher << " VND!" << RESET_COLOR << endl;
                    doanhThu += (tongTien - voucher);
                }
                else {
                    doanhThu += tongTien;
                }
            }
            else {
                cout << BLUE_COLOR << "Khong tim thay hoi vien voi so dien thoai '" << soDienThoai << "'" << RESET_COLOR << endl;
                doanhThu += tongTien;
            }
        }
        else {
            cout << BLUE_COLOR << "Ban co muon lam the hoi vien khong? (y/n): " << RESET_COLOR;
            char lamHoiVien;
            cin >> lamHoiVien;

            if (lamHoiVien == 'y' || lamHoiVien == 'Y') {
                cout << BLUE_COLOR << "Nhap so dien thoai: " << RESET_COLOR;
                string soDienThoai;
                cin >> soDienThoai;

                if (!isValidPhoneNumber(soDienThoai)) {
                    cout << BLUE_COLOR << "So dien thoai khong hop le. Vui long nhap lai!" << RESET_COLOR << endl;
                    return;
                }

                cout << BLUE_COLOR << "Nhap ten hoi vien: " << RESET_COLOR;
                cin.ignore();
                getline(cin, tenKhachHang);

                if (!isValidName(tenKhachHang)) {
                    cout << BLUE_COLOR << "Ten hoi vien khong hop le. Vui long nhap lai!" << RESET_COLOR << endl;
                    return;
                }

                danhSachHoiVien.push_back(KhachHang(soDienThoai, tenKhachHang));
                cout << BLUE_COLOR << "Da tao the hoi vien cho " << tenKhachHang << RESET_COLOR << endl;
                doanhThu += tongTien;
            }
            else {
                doanhThu += tongTien;
            }
        }
        system("cls");
        ban->thanhToan();
    }
    else {
        cout << BLUE_COLOR << "Khong tim thay ban an so " << soBan << RESET_COLOR << endl;
    }
}



void NhaHang::hienThiDoanhThu() const {
    double tongDoanhThu = 0;
    double tongChiPhi = 0;


    cout << "+-------------------------+\n";
    cout << "|    Bao cao doanh thu     |\n";
    cout << "+-------------------------+\n";
    cout << left << setw(10) << "Ma mon"
        << setw(20) << "Ten mon"
        << setw(10) << "So luong"
        << setw(10) << "Gia"
        << setw(15) << "Thanh tien"
        << setw(15) << "Chi phi"
        << setw(15) << "Loi nhuan" << endl;

    cout << "-----------------------------------------------------------\n";


    for (const auto& entry : soLuongMonBanRa) {
        int maMon = entry.first;
        int soLuong = entry.second;


        bool found = false;
        for (const MonAn& mon : menu) {
            if (std::to_string(maMon) == mon.getMaMon()) {

                double thanhTien = soLuong * mon.getGiaTien();
                double chiPhi = soLuong * mon.getChiPhi();
                double loiNhuan = thanhTien - chiPhi;


                cout << left << setw(10) << maMon
                    << setw(20) << mon.getTenMon()
                    << setw(10) << soLuong
                    << setw(10) << mon.getGiaTien()
                    << setw(15) << thanhTien
                    << setw(15) << chiPhi
                    << setw(15) << loiNhuan << endl;

                tongDoanhThu += thanhTien;
                tongChiPhi += chiPhi;
                found = true;
                break;
            }
        }


        if (!found) {
            cout << "Mon an ma " << maMon << " khong ton tai trong menu!" << endl;
        }
    }


    cout << "-----------------------------------------------------------\n";
    cout << "Tong doanh thu: " << tongDoanhThu << " VND\n";
    cout << "Tong chi phi: " << tongChiPhi << " VND\n";
    cout << "Tong loi nhuan: " << tongDoanhThu - tongChiPhi << " VND\n";
}


void NhaHang::themMenuSan() {
    themMonAnVaoMenu(MonAn("1", "Pho bo", "Mon chinh", 50000, 10000));
    themMonAnVaoMenu(MonAn("2", "Com ga", "Mon chinh", 45000, 10000));
    themMonAnVaoMenu(MonAn("3", "Tra sua", "Thuc uong", 30000, 10000));
    themMonAnVaoMenu(MonAn("4", "Goi cuon", "Khai vi", 20000, 10000));
    themMonAnVaoMenu(MonAn("5", "Ca phe", "Thuc uong", 25000, 10000));
    themMonAnVaoMenu(MonAn("6", "Banh mi", "Mon chinh", 20000, 10000));
    themMonAnVaoMenu(MonAn("7", "Xoi xeo", "Mon chinh", 35000, 10000));
    themMonAnVaoMenu(MonAn("8", "Bia", "Thuc uong", 15000, 10000));
    themMonAnVaoMenu(MonAn("9", "Sinh to", "Thuc uong", 20000, 10000));
    themMonAnVaoMenu(MonAn("10", "Chao long", "Mon chinh", 30000, 10000));
}

void NhaHang::themMonAn() {
    string ma, ten, loai;
    double gia, chiPhi;

    while (true) {
        cout << BLUE_COLOR << "Nhap ma mon an : " << RESET_COLOR;
        cin >> ma;
        cin.ignore();

        if (isNumber(ma)) break;
        else {
            cout << BLUE_COLOR << "Loi: Ma mon an chi duoc chua so! Vui long nhap lai." << RESET_COLOR << endl;
        }
    }


    while (true) {
        cout << BLUE_COLOR << "Nhap ten mon an: " << RESET_COLOR;
        getline(cin, ten);

        if (isAllLetters(ten)) break;
        else {
            cout << BLUE_COLOR << "Loi: Ten mon an chi duoc chua chu cai! Vui long nhap lai." << RESET_COLOR << endl;
        }
    }


    while (true) {
        cout << BLUE_COLOR << "Nhap loai mon an: " << RESET_COLOR;
        getline(cin, loai);

        if (isAllLetters(loai)) break;
        else {
            cout << BLUE_COLOR << "Loi: Loai mon an chi duoc chua chu cai! Vui long nhap lai." << RESET_COLOR << endl;
        }
    }



    gia = nhapSo("Nhap gia mon an: ");


    chiPhi = nhapSo("Nhap chi phi mon an: ");

    if (!kiemTraMonAnTonTai(MonAn(ma, ten, loai, gia, chiPhi))) {
        themMonAnVaoMenu(MonAn(ma, ten, loai, gia, chiPhi));
        cout << BLUE_COLOR << "Da them mon an vao menu!" << RESET_COLOR << endl;
    }
    else {
        cout << BLUE_COLOR << "Mon an da ton tai trong menu!" << RESET_COLOR << endl;
    }
}




void NhaHang::themHoiVien() {
    cout << BLUE_COLOR << "Nhap so dien thoai: " << RESET_COLOR;
    string soDienThoai;
    cin >> soDienThoai;


    if (!isValidPhoneNumber(soDienThoai)) {
        cout << BLUE_COLOR << "So dien thoai khong hop le. Vui long nhap lai!" << RESET_COLOR << endl;
        return;
    }

    cout << BLUE_COLOR << "Nhap ten hoi vien: " << RESET_COLOR;
    cin.ignore();
    string tenKhachHang;
    getline(cin, tenKhachHang);


    if (!isValidName(tenKhachHang)) {
        cout << BLUE_COLOR << "Ten hoi vien khong hop le. Vui long nhap lai!" << RESET_COLOR << endl;
        return;
    }


    danhSachHoiVien.push_back(KhachHang(soDienThoai, tenKhachHang));
    cout << BLUE_COLOR << "Da tao the hoi vien cho " << tenKhachHang << RESET_COLOR << endl;
}


void NhaHang::xoaHoiVien() {
    string ma;
    cout << BLUE_COLOR << "Nhap sdt hoi vien can xoa: " << RESET_COLOR;
    cin >> ma;

    auto it = danhSachHoiVien.begin();
    while (it != danhSachHoiVien.end()) {
        if (it->getSdt() == ma) {
            it = danhSachHoiVien.erase(it);
            cout << BLUE_COLOR << "Da xoa hoi vien voi so dien thoai: " << ma << RESET_COLOR << endl;
            return;
        }
        else {
            ++it;
        }
    }
    cout << BLUE_COLOR << "Khong tim thay hoi vien voi so dien thoai: " << ma << RESET_COLOR << endl;
}



KhachHang* NhaHang::timHoiVien(const string& maHoiVien) {
    for (auto& kh : danhSachHoiVien) {
        if (kh.getSdt() == maHoiVien) {
            return &kh;
        }
    }
    return nullptr;
}

NhanVien::NhanVien(string tenKH, string sdt, int t, string gt, string dc, double l, string cv)
    : KhachHang(sdt, tenKH), tuoi(t), gioiTinh(gt), diaChi(dc), luong(l), chucVu(cv) {}

int NhanVien::getTuoi() const { return tuoi; }
string NhanVien::getGioiTinh() const { return gioiTinh; }
string NhanVien::getDiaChi() const { return diaChi; }
double NhanVien::getLuong() const { return luong; }
string NhanVien::getChucVu() const { return chucVu; }

void NhanVien::setTuoi(int t) { tuoi = t; }
void NhanVien::setGioiTinh(const string& gt) { gioiTinh = gt; }
void NhanVien::setDiaChi(const string& dc) { diaChi = dc; }
void NhanVien::setLuong(double l) { luong = l; }
void NhanVien::setChucVu(const string& cv) { chucVu = cv; }

void NhanVien::hienThiThongTin() const {
    cout << left << setw(15) << getTen()
        << setw(15) << getSdt()
        << setw(5) << tuoi
        << setw(10) << gioiTinh
        << setw(20) << diaChi
        << right << setw(10) << fixed << setprecision(2) << luong
        << setw(15) << chucVu << endl;
}






void QuanLyNhanVien::themNhanVien(const NhanVien& nv) {
    danhSachNhanVien.push_back(nv);
}


void QuanLyNhanVien::xoaNhanVien(int index) {
    if (index >= 0 && index < danhSachNhanVien.size()) {
        danhSachNhanVien.erase(danhSachNhanVien.begin() + index);
    }
    else {
        cout << "Chi so nhan vien khong hop le!" << endl;
    }
}


void QuanLyNhanVien::hienThiDanhSachNhanVien() const {
    if (danhSachNhanVien.empty()) {
        cout << "Danh sach nhan vien rong!" << endl;
    }
    else {
        
        cout << left << setw(15) << "Ten"
            << setw(15) << "SDT"
            << setw(5) << "Tuoi"
            << setw(10) << "Gioi Tinh"
            << setw(20) << "Dia Chi"
            << setw(10) << "Luong"
            << setw(15) << "Chuc Vu" << endl;
        cout << string(90, '-') << endl;


        for (const auto& nv : danhSachNhanVien) {
            nv.hienThiThongTin();
        }
    }
}



void QuanLyNhanVien::danhSachNhanViensan() {
    themNhanVien(NhanVien("Duong Qua", "0123456789", 28, "Nam", "HCM", 1000, "Bao ve"));
    themNhanVien(NhanVien("Quach tinh", "0123456790", 25, "Nam", "HN", 1200, "Bep truong"));
    themNhanVien(NhanVien("Doc co cau bai", "0123456791", 58, "Nam", "DN", 1500, "Giam doc"));
    themNhanVien(NhanVien("Tran Thu Do", "0123456792", 35, "Nam", "HCM", 1100, "Phu bep"));
    themNhanVien(NhanVien("Hoang Thi E", "0123456793", 27, "Nam", "HN", 1300, "Phuc Vu"));
    themNhanVien(NhanVien("Vi Duy Doan", "0123456794", 32, "Nu", "HCM", 1400, "Thu ngan"));
    themNhanVien(NhanVien("Truong Thi G", "0123456795", 26, "Nu", "DN", 1000, "bep pho"));
    themNhanVien(NhanVien("Do Thi H", "0123456796", 40, "Nam", "HN", 1500, "Trong xe"));
    themNhanVien(NhanVien("Pham Thi I", "0123456797", 50, "Nam", "HCM", 1700, "Phuc vu"));
    themNhanVien(NhanVien("Nguyen Thi J", "0123456798", 29, "Nu", "HCM", 1600, "Phuc vu"));
}









