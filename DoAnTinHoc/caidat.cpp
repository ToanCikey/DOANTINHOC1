#include"thuvien.h"
void khoiTaoNhanVien(DSNV& list) {
	list = NULL;
}
int isEmptyNhanVien(DSNV list) {
	return list == NULL ? 1 : 0;
}
void giaiPhongNhanVien(DSNV& list) {
	DSNV p = list;
	while (p != NULL) {
		list = list->link;
		delete p;
		p = list;
	}
}
DSNV tao_Node_NV(NHANVIEN x) {
	DSNV p;
	p = new DSNHANVIEN;
	p->data1 = x;
	p->link = NULL;
	return p;
}
DSNV themDauNhanVien(DSNV& list, NHANVIEN x) {
	DSNV p = tao_Node_NV(x);
	p->link = list;
	list = p;
	return p;
}
bool kiemTra_MaNhanVien(DSNV& list, int ma) {
	DSNV p = list;
	while (p != NULL) {
		if (p->data1.manv == ma)
			return true;
		p = p->link;
	}
	return false;
}
void nhapNhanVien(NHANVIEN &nv) {
	cout << "\n Nhap ma nhan vien: ";
	cin >> nv.manv;
	cin.ignore();
	cout << "\n Nhap ten nhan vien: ";
	cin.getline(nv.hotennv, 50);
	cout << "\n Nhap gioi tinh: ";
	cin >> nv.gioitinh;
	cout << "\n Nhap luong: ";
	cin >> nv.luong;
}
void xuatNhanVien(NHANVIEN nv) {
	cout << "\n Ma nhan vien la: " << nv.manv;
	cout << "\n Ho ten nhan vien la: " << nv.hotennv;
	cout << "\n Gioi tinh nhan vien la: " << nv.gioitinh;
	cout << "\n Luong nhan vien la: " << nv.luong;
}
void nhapDanhSachNhanVien(DSNV& list) {
	NHANVIEN nv;
	khoiTaoNhanVien(list);
	do {
		cout << "\n Nhap MANV(NHAP 0 DE THOAT): ";
		cin >> nv.manv;
		while (kiemTra_MaNhanVien(list, nv.manv)) {
			cout << "\n Ma so bi trung.Vui long nhap lai!";
			cin >> nv.manv;
		}
		if (nv.manv==0) 
			break;
		cin.ignore();
		cout << "\n Ho ten nhan vien la: ";
		cin.getline(nv.hotennv, 50);
		cout << "\n Gioi tinh nhan vien la: ";
		cin.getline(nv.gioitinh, 5);
		cout << "\n Nhap luong: ";
		cin >> nv.luong;
		cin.ignore();
		themDauNhanVien(list, nv);
	} while (1);
}

void xuatDanhSachNhanVien(DSNV list) {
	cout << "\n Danh sach cac nhan vien:" << endl;
	cout << setw(0) << "MA NV" << setw(15) << "TEN NV" << setw(20) << "GIOI TINH"
		<< setw(10) << "LUONG" << endl;
	while (list != NULL) {
		cout << setw(0) << list->data1.manv << setw(20) << list->data1.hotennv<< setw(13) << list->data1.gioitinh
			<< setw(12) << list->data1.luong<< endl;
		list = list->link;
	}
}
//void khoiTaoPhongBan(DSPB& pb) {
//	pb = NULL;
//}
//int isEmptyPhongBan(DSPB pb) {
//	return pb == NULL ? 1 : 0;
//}
//void giaiPhongPhongBan(DSPB& pb) {
//	DSPB p = pb;
//	while (p != NULL) {
//		pb = pb->next;
//		delete p;
//		p = pb;
//	}
//}
//DSPB tao_Node_PB(PHONGBAN x) {
//	DSPB p;
//	p = new DSPHONGBAN;
//	p->data2 = x;
//	p->next = NULL;
//	return p;
//}
//DSPB themDauPhongBan(DSPB& pb, PHONGBAN x) {
//	DSPB p = tao_Node_PB(x);
//	p->next = pb;
//	pb = p;
//	return p;
//}
//bool kiemTra_MaPhongBan(DSPB& pb, int ma) {
//	DSPB p = pb;
//	while (p != NULL) {
//		if (p->data2.mapb== ma)
//			return true;
//		p = p->next;
//	}
//}
void nhapPhongBan(PHONGBAN &pb) {
	cout << "\n Nhap ma phong ban: ";
	cin >> pb.mapb;
	cout << "\n Nhap ten phong ban: ";
	cin.ignore();
	cin.getline(pb.tenpb, 30);
	nhapDanhSachNhanVien(pb.ds.link);
}
void xuatPhongBan(PHONGBAN pb) {
	cout << "\n Ma PB: "<<pb.mapb <<setw(0) << " Ten PB: " << setw(10) << pb.tenpb << setw(20) << endl;
	xuatDanhSachNhanVien(pb.ds.link);
}
void nhapDanhSachPhongBan(DSPHONGBAN &dspb){
	cout << "\n Nhap so luong phong ban: ";
	cin >> dspb.n;
	cout << "\n Nhap thong tin phong ban: ";
	for (int i = 0;i < dspb.n;i++) {
		cout << "\n Thong tin phong ban " << i + 1 << endl;
		nhapPhongBan(dspb.data[i]);
	}
}

void xuatDanhSachPhongBan(DSPHONGBAN dspb) {
	cout << "\n Danh sach cac phong ban:" << endl;
	for (int i = 0; i < dspb.n; i++)
	{
		xuatPhongBan(dspb.data[i]);
	}
}
void themNVVAOPB(PHONGBAN &pb1) {
	NHANVIEN nv;
	nhapNhanVien(nv);
	DSNV newNhanVien = new DSNHANVIEN;
	newNhanVien->data1 = nv;
	newNhanVien->link = NULL;

	if (pb1.ds.link == NULL) {
		pb1.ds.link = newNhanVien;
	}
	else {
		DSNV current = pb1.ds.link;
		while (current->link != NULL) {
			current = current->link;
		}
		current->link = newNhanVien;
	}

	cout << "\n Them nhan vien thanh cong !";
}
void themNVVaoDSPhongBan(DSPHONGBAN& dspb, int mapb) {
	int index = -1;
	for (int i = 0; i < dspb.n; i++)
	{
		PHONGBAN& pb = dspb.data[i];
		if (pb.mapb == mapb) {
			index = i;
			break;
		}
	}
	themNVVAOPB(dspb.data[index]);
	if (index == -1) {
		cout << "Khong tim thay phong ban " << mapb << endl;
	}
}
void themPBVAODSPB(DSPHONGBAN& dspb,int mapb) {
	PHONGBAN pb;
	if (dspb.n == MAXMAX) {
		cout << "\n So luong phong ban da day!";
	}
	else {
		nhapPhongBan(pb);
		dspb.data[dspb.n++] = pb;
		cout << "\n Them phong ban thanh cong.";
	}
}
void xoaNVKHOIPB(PHONGBAN &pb, int manv) {
	DSNHANVIEN& ds = pb.ds;
	DSNV current = ds.link;
	DSNV previous = NULL;
	while (current != NULL) {
		if (current->data1.manv == manv) {
			if (previous == NULL) {
				ds.link = current->link;
			}
			else {
				previous->link = current->link;
			}
			delete current;
			cout << "\n Xoa nhan vien thanh cong!!";
			return;
		}
		previous = current;
		current = current->link;
	}
	cout << "Khong tim thay nhan vien co ma " << manv << " trong phong ban " << pb.mapb << endl;
}
void xoaNVKHOIDSPB(DSPHONGBAN& dspb,int mapb,int manv) {
	for (int i = 0; i < dspb.n; i++)
	{
		PHONGBAN& pb = dspb.data[i];
		if (pb.mapb == mapb) {
			xoaNVKHOIPB(dspb.data[i], manv);
		}
	}
}
void xoaPBKHOIDSPB(DSPHONGBAN& dspb, int mapb) {
	for (int i = 0; i < dspb.n; i++)
	{
		PHONGBAN &pb = dspb.data[i];
		if (pb.mapb == mapb) {
			for (int j = i+1; j < dspb.n; j++)
			{
				dspb.data[j - 1] = dspb.data[j];
			}
			dspb.n--;
			cout << "\n Da xoa phong ban co ma " << mapb << " ra khoi danh sach phong ban thanh cong!";
			break;
		}
		else {
			cout << "\n Khong tim thay phong ban co ma " << mapb << "trong danh sach phong ban" << dspb.data[i].mapb << endl;
		}
	}
}

NHANVIEN timNVTheoTen(PHONGBAN pb, const char* ten) {
	DSNV nv = pb.ds.link;
	while (nv != NULL) {
		if (strcmp(nv->data1.hotennv, ten) == 0) {
			return nv->data1;
		}
		nv = nv->link;
	}
	
	NHANVIEN nvNull{};
	return nvNull;
}
NHANVIEN timNVTheoMa(PHONGBAN pb, int ma) {
	DSNV nv = pb.ds.link;
	while (nv != NULL) {
		if (nv->data1.manv==ma) {
			return nv->data1;
		}
		nv = nv->link;
	}
	NHANVIEN nvNull{};
	return nvNull;
}
void timNVTheoTenTrongDSPB(DSPHONGBAN& dspb, const char* ten, int mapb) {
	for (int i = 0;i < dspb.n;i++) {
		PHONGBAN pb = dspb.data[i];
		cout << "\n Thong tin phong ban: " << i + 1 << endl;
		cout << "\n Ma phong ban: " << dspb.data[i].mapb << endl;
		cout << "\n Ten phong ban: " << dspb.data[i].tenpb << endl;
		if (timNVTheoTen(pb,ten).manv !=0) {
			NHANVIEN nv = timNVTheoTen(pb, ten);
			cout << "\n Tim thay thanh cong!!";
			cout << "\n Ma nv:" << nv.manv;
			cout << "\n Ho ten nv:" << nv.hotennv;
			cout << "\n Gioi tinh nv:" << nv.gioitinh;
			cout << "\n Luong nv:" << nv.luong;
		}
		else {
			cout << "Khong tim thay nhan vien co ten tren";
			break;
		}
	}
}
void timNVTheoMaTrongDSPB(DSPHONGBAN& dspb, int manv, int mapb) {
	for (int i = 0;i < dspb.n;i++) {
		PHONGBAN pb = dspb.data[i];
		cout << "\n Thong tin phong ban: " << i + 1 << endl;
		cout << "\n Ma phong ban: " << dspb.data[i].mapb << endl;
		cout << "\n Ten phong ban: " << dspb.data[i].tenpb << endl;
		if (timNVTheoMa(pb, manv).manv != 0) {
			NHANVIEN nv = timNVTheoMa(pb, manv);
			cout << "\n Tim thay thanh cong!!";
			cout << "\n Ma nv:" << nv.manv;
			cout << "\n Ho ten nv:" << nv.hotennv;
			cout << "\n Gioi tinh nv:" << nv.gioitinh;
			cout << "\n Luong nv:" << nv.luong;
		}
		else {
			cout << "Khong tim thay nhan vien co ma tren";
			break;
		}
	}
}
int demSoNV(DSNV list) {
	int dem = 0;
	DSNV p = list;
	while (p != NULL) {
		dem++;
		p = p->link;
	}
	return dem;
}

void docDSNhanVienTuFile(istream& file, DSNV &list) {
	NHANVIEN nv;
	int n = 0;
	file >> n;
	khoiTaoNhanVien(list);
	for (int i = 0; i < n; i++) {
		file >> nv.manv;
		file.ignore();
		file.getline(nv.hotennv, 50);
		file.getline(nv.gioitinh, 5);
		file >> nv.luong;
		file.ignore();
		themDauNhanVien(list, nv);
	}
}
void docPhongBanTuFile(istream& file, PHONGBAN& pb) {
	file >> pb.mapb;
	file.ignore();
	file.getline(pb.tenpb,30);
	docDSNhanVienTuFile(file, pb.ds.link);
}
void docDSPhongBanTuFile(const char* File, DSPHONGBAN &dspb) {
	ifstream file(File);
	if (!file) {
		cout << "\n Loi khi mo file." << endl;
		return;
	}
	file >> dspb.n;
	file.ignore();
	for (int i = 0;i < dspb.n;i++) {
		docPhongBanTuFile(file, dspb.data[i]);
	}
	file.close();
}
void ghiDanhSachNhanVienVaoFile(ostream& file, DSNV& dsnv) {
	DSNV current = dsnv;
	file << demSoNV(dsnv) << endl;
	while (current != NULL) {
		file << current->data1.manv << endl;
		file << current->data1.hotennv << endl;
		file << current->data1.gioitinh << endl;
		file << current->data1.luong << endl;
		current = current->link;
	}
}
void ghiPhongBanVaoFile(ostream& file, PHONGBAN& pb) {
	file << pb.mapb << endl;
	file << pb.tenpb << endl;
	ghiDanhSachNhanVienVaoFile(file,pb.ds.link);
}
void ghiDSPhongBanVaoFile(const char* File, DSPHONGBAN& dspb) {
	ofstream file(File);
	if (!file) {
		cout << "\n Loi mo file." << endl;
		return;
	}
	file << dspb.n << endl;
	for (int i = 0;i < dspb.n;i++) {
		ghiPhongBanVaoFile(file, dspb.data[i]);
	}
	cout << "\n Ghi thanh cong!!" << endl;
	file.close();
}

void hienthi_Menu() {
	cout << "\n ==========================================================";
	cout << "\n ==           CAC CHUC NANG CHUONG TRINH                 ==";
	cout << "\n ==                                                      ==";
	cout << "\n ==  Moi ban chon !                                      ==";
	cout << "\n ==  1.Nhap 1 nhan vien                                  ==";
	cout << "\n ==  2.Xuat 1 nhan vien                                  ==";
	cout << "\n ==  3.Nhap danh sach nhan vien                          ==";
	cout << "\n ==  4.Xuat danh sach nhan vien                          ==";
	cout << "\n ==  5.Nhap 1 phong ban                                  ==";
	cout << "\n ==  6.Xuat 1 phong ban                                  ==";
	cout << "\n ==  7.Nhap danh sach phong ban                          ==";
	cout << "\n ==  8.Xuat danh sach phong ban                          ==";
	cout << "\n ==  9.Them 1 nhan vien vao 1 phong ban                  ==";
	cout << "\n ==  10.Them 1 nhan vien vao 1 danh sach phong ban       ==";
	cout << "\n ==  11.Them 1 phong ban vao 1 danh sach phong ban       ==";
	cout << "\n ==  12.Xoa 1 nhan vien khoi 1 phong ban                 ==";
	cout << "\n ==  13.Xoa 1 nhan vien khoi 1 danh sach phong ban       ==";
	cout << "\n ==  14.Xoa 1 phong ban khoi 1 danh sach phong ban       ==";
	cout << "\n ==  15.Tim kiem nhan vien theo ten                      ==";
	cout << "\n ==  16.Tim kiem nhan vien theo ma                       ==";
	cout << "\n ==  17.Tim kiem nhan vien theo ten trong 1 DSPB         ==";
	cout << "\n ==  18.Tim kiem nhan vien theo ma trong 1 DSPB          ==";
	cout << "\n ==  19.Ghi File                                         ==";
	cout << "\n ==  20.Doc File                                         ==";
	cout << "\n ==  0. Thoat chuong trinh !                             ==";
	cout << "\n ==                                                      ==";
	cout << "\n ==========================================================";
}
void chon_Menu() {
	NHANVIEN nv;
	PHONGBAN pb{};
	DSNV dsnv{};
	DSPHONGBAN dspb{};
	int luachon;
	do {
		cout << "\n moi ban nhap lua chon chuc nang:";
		cin >> luachon;
		switch (luachon)
		{
		case 0:
			break;
		case 1:
			system("cls");
			nhapNhanVien(nv);
			hienthi_Menu();
			break;
		case 2:
			system("cls");
			xuatNhanVien(nv);
			hienthi_Menu();
			break;
		case 3:
			system("cls");
			khoiTaoNhanVien(dsnv);
			nhapDanhSachNhanVien(dsnv);
			hienthi_Menu();
			break;
		case 4:
			system("cls");
			xuatDanhSachNhanVien(dsnv);
			hienthi_Menu();
			break;
		case 5:
			system("cls");
			nhapPhongBan(pb);
			hienthi_Menu();
			break;
		case 6:
			system("cls");
			xuatPhongBan(pb);
			hienthi_Menu();
			break;
		case 7:
			system("cls");
			nhapDanhSachPhongBan(dspb);
			hienthi_Menu();
			break;
		case 8:
			system("cls");
			xuatDanhSachPhongBan(dspb);
			hienthi_Menu();
			break;
		case 9:
			system("cls");
			themNVVAOPB(pb);
			//xuatPhongBan(pb);
			hienthi_Menu();
			break;
		case 10:
			system("cls");
			int maPB1;
			cout << "\n Nhap ma phong ban muon them nhan vien:";
			cin >> maPB1;
			themNVVaoDSPhongBan(dspb,maPB1);
			//xuatPhongBan(pb);
			hienthi_Menu();
			break;
		case 11:
			system("cls");
			int mapb1;
			cout << "\n nhap phong ban can them:";
			cin >> mapb1;
			themPBVAODSPB(dspb,mapb1);
			//xuatDanhSachPhongBan(dspb);
			hienthi_Menu();
			break;
		case 12:
			system("cls");
			int maNV;
			cout << "\n Nhap ma nhan vien can xoa:";
			cin >> maNV;
			xoaNVKHOIPB(pb,maNV);
			//xuatPhongBan(pb);
			hienthi_Menu();
			break;
		case 13:
			system("cls");
			int maPB;
			cout << "\n Nhap ma phong ban muon xoa nhan vien:";
			cin >> maPB;
			int maNVXoa;
			cout << "\n Nhap ma nhan vien can xoa:";
			cin >> maNVXoa;
			xoaNVKHOIDSPB(dspb,maPB,maNVXoa);
			//xuatPhongBan(pb);
			hienthi_Menu();
			break;
		case 14:
			system("cls");
			int mapb;
			cout << "\n Nhap ma phong ban can xoa:";
			cin >> mapb;
			xoaPBKHOIDSPB(dspb, mapb);
			hienthi_Menu();
			break;
		case 15:
			system("cls");
			char tennv[30];
			cout << "\n Nhap ten nhan vien muon tim ?";
			cin >> tennv;
			timNVTheoTen(pb, tennv);
			hienthi_Menu();
			break;
		case 16:
			system("cls");
			int manv;
			cout << "\n Nhap ma nhan vien muon tim ?";
			cin >> manv;
			timNVTheoMa(pb, manv);
			hienthi_Menu();
			break;
		case 17:
			system("cls");
			int mapba;
			cout << "\n Nhap ma phong ban muon tim:";
			cin >> mapba;
			char tennvtrongdspb[30];
			cout << "\n Nhap ten nhan vien muon tim ?";
			cin >> tennvtrongdspb;
			timNVTheoTenTrongDSPB(dspb, tennvtrongdspb, mapba);
			hienthi_Menu();
			break;
		case 18:
			system("cls");
			int mapba1;
			cout << "\n Nhap ma phong ban muon tim:";
			cin >> mapba1;
			int manvtrongdspb;
			cout << "\n Nhap ma nhan vien muon tim ?";
			cin >> manvtrongdspb;
			timNVTheoMaTrongDSPB(dspb, manvtrongdspb, mapba1);
			hienthi_Menu();
			break;
		case 19:
			system("cls");
			/*char tenfileghi[20];
			cout << "\n nhap ten file muon ghi? ";
			cin >> tenfileghi;*/
			ghiDSPhongBanVaoFile("danhsach.txt", dspb);
			hienthi_Menu();
			break;
		case 20:
			system("cls");
			/*char tenfiledoc[20];
			cout << "\n nhap ten file muon doc? ";
			cin >> tenfiledoc;*/
			docDSPhongBanTuFile("danhsach.txt", dspb);
			xuatDanhSachPhongBan(dspb);
			hienthi_Menu();
			break;
		default:
			break;
		}
	} while (luachon != 0);
}
