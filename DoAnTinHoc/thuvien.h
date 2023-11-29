#define _CRT_SECURE_NO_WARINGS
#include<iostream>
#include<string.h>
#include<iomanip>
#include <fstream>
using namespace std;
const int MAX = 50;
const int MAXMAX = 10;
typedef struct DSNHANVIEN* DSNV;
typedef struct DSPHONGBAN* DSPB;
struct NHANVIEN {
	int manv;
	char hotennv[50];
	char gioitinh[5];
	double luong;
};
struct DSNHANVIEN {
	NHANVIEN data1;
	DSNV link;
};
struct PHONGBAN {
	int mapb;
	char tenpb[30];
	DSNHANVIEN ds;
};
struct DSPHONGBAN {
	int n;
	PHONGBAN data[MAXMAX];
};
void khoiTaoNhanVien(DSNV &list);
int isEmptyNhanVien(DSNV list);
void giaiPhongNhanVien(DSNV &list);
DSNV tao_Node_NV(NHANVIEN x);
DSNV themDauNhanVien(DSNV& list, NHANVIEN x);
bool kiemTra_MaNhanVien(DSNV& list, int ma);
//void khoiTaoPhongBan(DSPB& pb);
//int isEmptyPhongBan(DSPB pb);
//void giaiPhongPhongBan(DSPB& pb);
//DSPB tao_Node_PB(PHONGBAN x);
//DSPB themDauPhongBan(DSPB& pb, PHONGBAN x);
//bool kiemTra_MaPhongBan(DSPB& pb,int ma);
void nhapNhanVien(NHANVIEN &nv);
void xuatNhanVien(NHANVIEN nv);
void nhapDanhSachNhanVien(DSNV &list);
void xuatDanhSachNhanVien(DSNV list);
void nhapPhongBan(PHONGBAN &pb);
void xuatPhongBan(PHONGBAN pb);
void nhapDanhSachPhongBan(DSPHONGBAN &dspb);
void xuatDanhSachPhongBan(DSPHONGBAN dspb);
void themNVVAOPB(PHONGBAN& p1);
void themNVVaoDSPhongBan(DSPHONGBAN& dspb, int mapb);
void themPBVAODSPB(DSPHONGBAN& dspb,int mapb);
void xoaNVKHOIPB(PHONGBAN &pb,int manv);
void xoaNVKHOIDSPB(DSPHONGBAN& dspb, int mapb, int manv);
void xoaPBKHOIDSPB(DSPHONGBAN& dspb, int mapb);
NHANVIEN timNVTheoTen(PHONGBAN pb, const char *ten);
NHANVIEN timNVTheoMa(PHONGBAN pb, int ma);
void timNVTheoTenTrongDSPB(DSPHONGBAN& dspb, const char* ten,int mapb);
void timNVTheoMaTrongDSPB(DSPHONGBAN& dspb, int manv, int mapb);
void docDSNhanVienTuFile(istream& file, DSNV& dsnv);
void docPhongBanTuFile(istream& file, PHONGBAN& pb);
void docDSPhongBanTuFile(const char* File, DSPHONGBAN& dspb);
void ghiDanhSachNhanVienVaoFile(ostream& file, DSNV& dsnv);
void ghiPhongBanVaoFile(ostream& file, PHONGBAN& pb);
void ghiDSPhongBanVaoFile(const char* File, DSPHONGBAN& dspb);
int demSoNV(DSNV list);
void hienthi_Menu();
void chon_Menu();
