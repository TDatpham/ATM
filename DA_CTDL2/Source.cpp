#include <iostream>
#include <fstream>
#include "Admin.h"
#include "User.h"
#include <vector>
#include <string>
#include <conio.h>
#include <iomanip>
#include <Windows.h>
using namespace std;


vector<User> gDanhSachUser;
vector<Admin> ds;
User tmpUser;
int pos = -1; //vị trí của User trong danh sách

//Admin
void menuAdmin();
void dangNhapAdmin();
void xemDanhSachTaiKhoan();
void themTaiKhoan();
void moKhoaTaiKhoan();
void xoaTaiKhoan();
void capNhatTaiKhoan();
vector<Admin> lapDanhSachAdmin();
//User
vector<User> lapDanhSachUser();
void menuUser();
void dangNhapUser();
void xemThongTinTaiKhoan();
void rutTien();
void chuyenTien();
void xemLichSuGiaoDich();
void doiMaPIN();

//Hàm bổ trợ
bool kiemTraTien(long money);
int timID(string id);
void thoiGian();
void getData(string& s, int size, bool hide);
void WelcomeScreen();
void textColor(int x);

int main() {

	gDanhSachUser = lapDanhSachUser();
	ds = lapDanhSachAdmin();
	WelcomeScreen();

	return 0;
}
//void WelcomeScreen() {
//	textColor(9);
//	system("cls");
//	cout << "\t\t\t\t* * * * * * * * * * *" << endl;
//	cout << "\t\t\t\t*      WELCOME      *" << endl;
//	cout << "\t\t\t\t* * * * * * * * * * *" << endl;
//	cout << "\t\t\t\t1. Dang nhap Admin" << endl;
//	cout << "\t\t\t\t2. Dang nhap User" << endl;
//	cout << "\t\t\t\t3. Thoat" << endl;
//labeldangnhap:
//	int choice;
//	cout << "\t\t\t\tMoi chon: ";
//	textColor(2);
//	cin >> choice;
//	switch (choice) {
//	case 1:
//		dangNhapAdmin();
//		break;
//	case 2:
//		dangNhapUser();
//		break;
//	case 3:
//		capNhatTaiKhoan();
//		exit(0);
//	default:
//		textColor(4);
//		cout << "\t\t\t\tChon sai! Vui long chon lai!\n";
//		textColor(9);
//		goto labeldangnhap;
//		break;
//	}
//}


void WelcomeScreen() {
	const int NUM_CHOICES = 4;
	int currentChoice = 1;

	while (true) {
		system("cls");
		textColor(6);
		cout << "\t\t\t\t __________________________________________ \n";
		cout << "\t\t\t\t|                                          |\n";
		cout << "\t\t\t\t|                 XIN CHAO !               |\n";
		cout << "\t\t\t\t|__________________________________________|\n";

		for (int i = 1; i < NUM_CHOICES; i++) {
			if (i == currentChoice) {
				textColor(2);
				cout << "\t\t\t\t-> ";
			}
			else {
				textColor(6);
				cout << "\t\t\t\t   ";
			}
				

			switch (i) {
			case 1:
				cout << "1. Dang nhap Admin" << endl;
				break;
			case 2:
				cout << "2. Dang nhap User" << endl;
				break;
			case 3:
				cout << "3. Thoat" << endl;
				break;
			default:
				break;
			}
		}

		int key = _getch();

		if (key == 224) { // Arrow key (extended code)
			key = _getch(); // Read the actual arrow key code

			if (key == 72) { // Up arrow
				currentChoice = (currentChoice - 1 + NUM_CHOICES) % NUM_CHOICES;
			}
			else if (key == 80) { // Down arrow
				currentChoice = (currentChoice + 1) % NUM_CHOICES;
			}
		}
		else if (key == 13) { // Enter key
			switch (currentChoice) {
			case 1:
				dangNhapAdmin(); // Gọi hàm dangNhapAdmin() khi chọn 1
				break;
			case 2:
				dangNhapUser(); // Gọi hàm dangNhapUser() khi chọn 2
				break;
			case 3:
				capNhatTaiKhoan();
				exit(0);
			default:
				break;
			}
		}
	}
}

// admin

vector<Admin> lapDanhSachAdmin() {
	string id, pin;
	vector<Admin> tmp;
	ifstream ifile("Admin.txt");
	while (ifile >> id >> pin) {
		Admin x(id, pin);
		tmp.push_back(x);
	}
	return tmp;
}
void menuAdmin()
{
	const int NUM_CHOICES = 7;
	int currentChoice = 1;

	while (true) {
		system("cls");
		textColor(9);
		cout << "\t\t\t\t ___________________________________________ \n";
		cout << "\t\t\t\t|                                           |\n";
		cout << "\t\t\t\t|                  MENU ADMIN               |\n";
		cout << "\t\t\t\t|___________________________________________|\n";

		for (int i = 1; i < NUM_CHOICES; i++) {
			if (i == currentChoice) {
				textColor(2);
				cout << "\t\t\t\t-> ";
			}
			else {
				textColor(9);
				cout << "\t\t\t\t   ";
			}

			switch (i)
			{
			case 1:
				cout << "1. Xem danh sach tai khoan\n";
				break;
			case 2:
				cout << "2. Them tai khoan\n";
				break;
			case 3:
				cout << "3. Mo tai khoan\n";
				break;
			case 4:
				cout << "4. Xoa tai khoan\n";
				break;
			case 5:
				cout << "5. Quay lai\n";
				break;
			case 6:
				cout << "6. Thoat\n";
				break;
			default:
				break;
			}
		}
		int key = _getch();

		if (key == 224) { // Arrow key (extended code)
			key = _getch(); // Read the actual arrow key code

			if (key == 72) { // Up arrow
				currentChoice = (currentChoice - 1 + NUM_CHOICES) % NUM_CHOICES;
			}
			else if (key == 80) { // Down arrow
				currentChoice = (currentChoice + 1) % NUM_CHOICES;
			}
		}
		else if (key == 13) { // Enter key
			switch (currentChoice) {
			case 1:
				xemDanhSachTaiKhoan();
				break;
			case 2:
				themTaiKhoan();
				break;
			case 3:
				moKhoaTaiKhoan();
				break;
			case 4:
				xoaTaiKhoan();
				break;
			case 5:
				capNhatTaiKhoan();
				WelcomeScreen();
				break;
			case 6:
				capNhatTaiKhoan();
				exit('0');
				break;
			default:
				textColor(9);
				menuAdmin();
				break;
			}

		}
	}
}

void dangNhapAdmin() {
	system("cls");
	textColor(9);
	cout << "\t\t\t\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
	cout << "\t\t\t\t*       DANG NHAP ADMIN     *" << endl;
	cout << "\t\t\t\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
	string id, pin;
	//ID admin ko yeu cau gioi han ki tu
	char x = 'a';
	cout << "\t\t\t\t Nhap ID:  ";
	textColor(2);
	while (x != 13) {
		x = _getch();
		if (x == 13) {
			break;
		}
		else if (x == 32) {
			continue;
		}
		else if (x == 8) {
			if (id.size() != 0) {
				id.pop_back();
				cout << "\b \b";
			}
		}
		else {
			id.push_back(x);
			cout << x;
		}
	}
	//PIN admin ko yeu cau gioi han ki tu
	textColor(9);
	cout << endl << "\t\t\t\t Nhap PIN: ";
	pin = "";
	textColor(2);
	x = 'a';
	while (x != 13) {
		x = _getch();
		if (x == 13) {
			break;
		}
		else if (x == 32) {
			continue;
		}
		else if (x == 8) {
			if (pin.size() != 0) {
				pin.pop_back();
				cout << "\b \b";
			}
		}
		else {
			pin.push_back(x);
			cout << x;
			cout << "\b \b*";
		}
	}
	cout << endl;
	textColor(9);
	bool check = false;
	for (int i = 0; i < ds.size(); i++) {
		if (id == ds[i].getID() && pin == ds[i].getPIN()) {
			check = true;
			break;
		}
	}
	if (check) {
		menuAdmin();
	}
	else {
		textColor(4);
		cout << "\t\t\t\tNhap sai thong tin !\n";
		textColor(9);
		system("pause");
		WelcomeScreen();
	}
}

void xemDanhSachTaiKhoan() {
	system("cls");
	textColor(9);
	cout << "\t\t\t\t~~~~~~~~~~~ XEM DANH SACH TAI KHOAN ~~~~~~~~~~~\n";
	cout << "\t\t\t\t" << left << setw(20) << "ID" << setw(20) << "PIN" << endl;
	textColor(2);
	for (int i = 0; i < gDanhSachUser.size(); i++) {
		cout << "\t\t\t\t" << setw(20) << gDanhSachUser[i].getID() << setw(20) << gDanhSachUser[i].getPIN() << endl;
	}
	textColor(9);
	cout << "\t\t\t\tTong so tai khoan: ";
	textColor(2);
	cout<< gDanhSachUser.size() << endl;
	textColor(9);
	system("pause");
	menuAdmin();
}
void themTaiKhoan() {
	User u;
	string id,pin,tenTaiKhoan,loaiTienTe;
	long soDu;
	system("cls");
	textColor(9);
	cout << "\t\t\t\t* * * * * * * * * *THEM TAI KHOAN* * * * * * * * * *\n";
	cout << "\t\t\t\tNhap thong tin User\n";
	cout << "\t\t\t\tID(14 chu so):   ";
	textColor(2);
	getData(id, 14, 0);
	u.setID(id);
	if (timID(u.getID()) != -1) {
		textColor(4);
		cout << "\t\t\t\tID da ton tai!\n";
		textColor(9);
		system("pause");
		menuAdmin();
	}
	textColor(9);
	cout << "\t\t\t\tPIN(6 chu so):   ";
	textColor(2);
	pin = "123456";
	cout << pin << " (mac dinh)\n";
	u.setPIN(pin);
	textColor(9);
	cout << "\t\t\t\tTen tai khoan:   ";
	textColor(2);
	cin.ignore();
	getline(cin, tenTaiKhoan);
	u.setTenTaiKhoan(tenTaiKhoan);
	textColor(9);
	cout << "\t\t\t\tSo du tai khoan: ";
	textColor(2);
	cin >> soDu;
	u.setSoDu(soDu);
	textColor(9);
	cout << "\t\t\t\tLoai tien te:    ";
	textColor(2);
	cin >> loaiTienTe;
	u.setLoaiTienTe(loaiTienTe);
	textColor(4);
	cout << "\t\t\t\tThem tai khoan thanh cong!\n";
	textColor(9);
	gDanhSachUser.push_back(u);
	ofstream ofile("TheTu.txt", ios::app);
	ofile << u.getID() << " " << u.getPIN() << endl;
	ofile.close();
	system("pause");
	capNhatTaiKhoan();
	menuAdmin();
}
void moKhoaTaiKhoan()
{  
	system("cls");
	string id;
labelmoKhoaTaiKhoan:
	textColor(9);
	cout << "\t\t\t\t* * * * * * * * *MO KHOA TAI KHOAN* * * * * * * * *\n";
	cout << "\t\t\t\tNhap ID can mo khoa:\t";
	textColor(2);
	getData(id, 14, 0);
	textColor(9);
	int vitri = timID(id);
	if (vitri != -1) {
		gDanhSachUser[vitri].setUnlock(true);
		textColor(4);
		cout << "\t\t\t\tMo khoa tai khoan thanh cong!\n";
		textColor(9);
		system("pause");
		capNhatTaiKhoan();
		menuAdmin();
	}
	textColor(4);
	cout << "\t\t\t\tKhong tim thay ID!\n";
	textColor(9);
	system("pause");
	menuAdmin();
}
void xoaTaiKhoan()
{
	system("cls");
	ifstream ifile("TheTu.txt");
	string id;
labelxoaTaiKhoan:
	textColor(9);
	cout << "\t\t\t\t* * * * * * * * * *XOA TAI KHOAN* * * * * * * * * *\n";
	cout << "\t\t\t\tNhap ID cua tai khoan:\t";
	textColor(2);
	getData(id, 14, 0);
	int vitri = timID(id);
	if (vitri != -1) {
		gDanhSachUser.erase(gDanhSachUser.begin() + vitri);
		textColor(4);
		cout << "\t\t\t\tXoa tai khoan thanh cong!\n";
		textColor(9);
		system("pause");
		capNhatTaiKhoan();
		menuAdmin();
	}
	textColor(4);
	cout << "\t\t\t\tKhong tim thay ID!\n";
	textColor(9);
	system("pause");
	menuAdmin();
}
void capNhatTaiKhoan()
{
	ofstream ofile("TheTu.txt");
	for (int i = 0; i < gDanhSachUser.size(); i++)
		ofile << gDanhSachUser[i].getID() << " " << gDanhSachUser[i].getPIN() << endl;
	ofile.close();
	ofile.open("[ID].txt");
	ofile << gDanhSachUser.size() << endl;
	for (int i = 0; i < gDanhSachUser.size(); i++) {
		ofile << gDanhSachUser[i].getID() << endl;
		ofile << gDanhSachUser[i].getTen() << endl;
		ofile << gDanhSachUser[i].getSoDu() << endl;
		ofile << gDanhSachUser[i].getLoaiTienTe() << endl;
		ofile << gDanhSachUser[i].getUnLock() << endl;
	}
	ofile.close();
}

//User
vector<User> lapDanhSachUser() {
	vector<User> tmp;
	ifstream ifile("[ID].txt");
	string id, pin, tentaikhoan, loaitiente;
	long sodutaikhoan;
	bool unlock;
	User u;
	int size;
	ifile >> size;
	string tam;
	for (int i = 0; i < size; i++) {
		ifile >> id ;
		getline(ifile, tam);//doc ki tu xuong dong
		getline(ifile, tentaikhoan);
		ifile>> sodutaikhoan >> loaitiente >> unlock;
		u.setUser(id, tentaikhoan, sodutaikhoan, loaitiente, unlock);
		tmp.push_back(u);
	}

	ifile.close();
	ifile.open("TheTu.txt");
	int i = 0;
	while (ifile >> id >> pin) {
		tmp[i++].setPIN(pin);
		if (i == tmp.size())
			break;
	}
	ifile.close();
	return tmp;
}


void menuUser()
{
	const int NUM_CHOICES = 8;
	int currentChoice = 1;

	while (true) {
		system("cls");
		textColor(9);
		cout << "\t\t\t\t ___________________________________________ \n";
		cout << "\t\t\t\t|                                           |\n";
		cout << "\t\t\t\t|                  MENU USER                |\n";
		cout << "\t\t\t\t|___________________________________________|\n";

		for (int i = 1; i < NUM_CHOICES; i++) {
			if (i == currentChoice) {
				textColor(2);
				cout << "\t\t\t\t-> ";
			}
			else {
				textColor(9);
				cout << "\t\t\t\t   ";
			}

			switch (i)
			{
			case 1:
				cout << "1. Xem thong tin tai khoan\n";
				break;
			case 2:
				cout << "2. Rut tien\n";
				break;
			case 3:
				cout << "3. Chuyen tien\n";
				break;
			case 4:
				cout << "4. Xem noi dung giao dich\n";
				break;
			case 5:
				cout << "5. Doi ma PIN\n";
				break;
			case 6:
				cout << "6. Quay lai\n";
				break;
			case 7:
				cout << "7. Thoat\n";
				break;
			default:
				break;
			}
		}
		int key = _getch();

		if (key == 224) { // Arrow key (extended code)
			key = _getch(); // Read the actual arrow key code

			if (key == 72) { // Up arrow
				currentChoice = (currentChoice - 1 + NUM_CHOICES) % NUM_CHOICES;
			}
			else if (key == 80) { // Down arrow
				currentChoice = (currentChoice + 1) % NUM_CHOICES;
			}
		}
		else if (key == 13) { // Enter key
			switch (currentChoice) {
			case 1:
				xemThongTinTaiKhoan();
				break;
			case 2:
				rutTien();
				break;
			case 3:
				chuyenTien();
				break;
			case 4:
				xemLichSuGiaoDich();
				break;
			case 5:
				doiMaPIN();
				break;
			case 6:
				WelcomeScreen();
				break;
			case 7:
				capNhatTaiKhoan();
				exit(0);
			default:
				textColor(9);
				menuUser();
				break;
			}

		}
	}
}
void dangNhapUser() {
lableNhapID:
	system("cls");
	string x, y;
	textColor(9);
	cout << "\t\t\t\t* * * * * * * * * * * * * * * * * * * *\n";
	cout << "\t\t\t\t*            DANG NHAP USER           *\n";
	cout << "\t\t\t\t* * * * * * * * * * * * * * * * * * * *\n";
	textColor(9);
	cout << "\t\t\t\tID:  ";
	textColor(2);
	getData(x, 14, 0);
	textColor(9);
	pos = -1; //vị trí User đăng nhập trong danh sách
	for (int i = 0; i < gDanhSachUser.size(); i++) {
		if (gDanhSachUser[i].getID() == x) {
			pos = i;
			break;
		}
	}
	if (pos == -1) {
		textColor(4);
		cout << "\t\t\t\tMa ID sai hoac chua co!\n";
		textColor(9);
		cout << "\t\t\t\t-------------------------\n";
		cout << "\t\t\t\t1. Quay lai Menu\n";
		cout << "\t\t\t\t2. Tiep tuc\n";
		int choice;
		textColor(2);
		cin >> choice;
		textColor(9);
		if (choice == 1)
			WelcomeScreen();
		else 
			goto lableNhapID;
	}

	string pin = gDanhSachUser[pos].getPIN();
	int dem = 0;
	textColor(9);
	cout << "\t\t\t\tPIN: ";
labelnhapMaPIN:
	textColor(2);
	getData(y, 6, 1);
	textColor(9);
	if (pin != y) {
		++dem;
		if (dem == 3) {
			gDanhSachUser[pos].setUnlock(false);
			textColor(4);
			cout << "\n\t\t\t\tNhap sai qua 3 lan. Tai khoan bi khoa" << endl;
			textColor(9);
			system("pause");
			WelcomeScreen();
		}
		else {
			textColor(9);
			cout << "\n\t\t\t\tNhap lai ma PIN:\t";
			goto labelnhapMaPIN;
		}
	}
	else {
		if (gDanhSachUser[pos].getUnLock() == false) {
			textColor(4);
			cout << "\n\t\t\t\tTai khoan cua ban da bi khoa \n";
			textColor(9);
			system("pause");
			WelcomeScreen();
		}
		else {
			tmpUser = gDanhSachUser[pos];
			menuUser();
		}
	}
}
void xemThongTinTaiKhoan()
{
	system("cls");
	textColor(9);
	cout << "\t\t\t\t* * * * * * * *THONG TIN TAI KHOAN* * * * * * * *\n";
	cout << "\t\t\t\tID:              ";
	textColor(2);
	cout << gDanhSachUser[pos].getID() << endl;
	textColor(9);
	cout << "\t\t\t\tPIN:             ";
	textColor(2);
	cout << gDanhSachUser[pos].getPIN() << endl;
	textColor(9);
	cout << "\t\t\t\tTen tai khoan:   ";
	textColor(2);
	cout << gDanhSachUser[pos].getTen() << endl;
	textColor(9);
	cout << "\t\t\t\tSo du tai khoan: ";
	textColor(2);
	cout << gDanhSachUser[pos].getSoDu() << endl;
	textColor(9);
	cout << "\t\t\t\tLoai tien te:    ";
	textColor(2);
	cout << gDanhSachUser[pos].getLoaiTienTe() << endl;
	textColor(9);
	system("pause");
	menuUser();
}
void rutTien()
{
	system("cls");
	long tienrut; // so tien rut
	textColor(9);
	cout << "\t\t\t\t* * * * * * * * * * * *RUT TIEN* * * * * *  * * * * * *\n";
	cout << "\t\t\t\tSo du tai khoan hien tai: ";
	textColor(2); 
	cout<< gDanhSachUser[pos].getSoDu() << " " << gDanhSachUser[pos].getLoaiTienTe() << endl;
	textColor(9);
	cout << "\t\t\t\tNhap so tien ban muon rut: ";
	textColor(2);
	cin >> tienrut;
	textColor(9);
	if (kiemTraTien(tienrut) == true)
	{
		fstream ofile;
		ofile.open("[LichSuID].txt", ios::app);
		textColor(4);
		cout << "\t\t\t\tBan da rut thanh cong\n";
		textColor(9);
		cout << "\t\t\t\tSo du tai khoan hien tai: ";
		textColor(2);
		cout << gDanhSachUser[pos].getSoDu() - tienrut << " " << gDanhSachUser[pos].getLoaiTienTe() << endl;
		textColor(9);
		long tmp = gDanhSachUser[pos].getSoDu() - tienrut;
		gDanhSachUser[pos].setSoDu(tmp);
		// ghi lai lich su giao dich
		thoiGian();
		ofile << gDanhSachUser[pos].getID() << " rut: " << tienrut << " " << gDanhSachUser[pos].getLoaiTienTe() << " " << endl;

		ofile.close();
		system("pause");
		menuUser();
	}
	else {
		textColor(4);
		cout << "\t\t\t\tVui long kiem tra so tien can rut va so du tai khoan!\n";
		textColor(9);
		cout << "\t\t\t\t-------------------------\n";
		cout << "\t\t\t\t1. Quay lai Menu\n";
		cout << "\t\t\t\t2. Tiep tuc rut tien\n";
		cout << "\t\t\t\tMoi chon: ";
		int choice;
		textColor(2);
		cin >> choice;
		textColor(9);
		if (choice == 1)
			menuUser();
		else
			rutTien();
	}
}
void chuyenTien() {
	system("cls");
	string id;
labeltimID:
	cout << "\t\t\t\t* * * * * * * * * * * CHUYEN TIEN* * * * * * * * * * *\n";
	cout << "\t\t\t\tNhap ID can chuyen tien den: ";
	textColor(2);
	getData(id, 14, 0);
	textColor(9);
	int vitri = timID(id);
	if (id == gDanhSachUser[pos].getID()) {
		textColor(4);
		cout << "\t\t\t\tID chuyen den trung voi ID cua ban!\n";
		textColor(9);
		system("pause");
		menuUser();
	}
	else if (vitri = timID(id) != -1) {
		long tiencanchuyen;
	labelnhapSoTien:
		cout << "\t\t\t\tNhap so tien can chuyen: ";
		textColor(2);
		cin >> tiencanchuyen;
		textColor(9);
		if (kiemTraTien(tiencanchuyen)) {
			ofstream ofile("[LichSuID].txt", ios::app);
			cout << "\t\t\t\tChuyen tien thanh cong ";
			textColor(2);
			cout << tiencanchuyen;
			textColor(9);
			cout << " " << gDanhSachUser[vitri].getLoaiTienTe() << " cho ID: ";
			textColor(2);
			cout<< id << endl;
			textColor(9);
			ofile << gDanhSachUser[pos].getID() << " chuyen " << tiencanchuyen << " " << gDanhSachUser[vitri].getLoaiTienTe() << " cho " << id << " ";
			thoiGian();
			ofile.close();
			gDanhSachUser[pos].setSoDu(gDanhSachUser[pos].getSoDu() - tiencanchuyen);
			gDanhSachUser[vitri].setSoDu(gDanhSachUser[vitri].getSoDu() + tiencanchuyen);
			system("pause");
			menuUser();
		}
		else {
			textColor(4);
			cout << "\t\t\t\tVui long kiem tra so tien can chuyen va so du tai khoan\n";
			textColor(9);
			cout << "\t\t\t\t-------------------------\n";
			cout << "\t\t\t\t1. Quay lai Menu\n";
			cout << "\t\t\t\t2. Tiep tuc chuyen tien\n";
			textColor(2);
			int choice;
			cin >> choice;
			textColor(9);
			if (choice == 2)
				goto labelnhapSoTien;
			else 
				menuUser();
		}
	}
	else {
		textColor(4);
		cout << "\t\t\t\tKhong tim thay ID!\n";
		textColor(9);
		system("pause");
		menuUser();
	}
}
void xemLichSuGiaoDich() {
	system("cls");
	textColor(9);
	cout << "\t\t\t\t* * * * * * * * *LICH SU GIAO DICH* * * * * * * * *\n";
	bool checkHistory = false;
	string ngay, vngay, gio, vgio, id1, t, sotien, loaitiente, cho, id2;
	ifstream ifile("[LichSuID].txt");
	while (ifile >> ngay >> vngay >> gio >> vgio >> id1 >> t >> sotien >> loaitiente) {
		if (t == "chuyen") {
			ifile >> cho >> id2;
			if (id1 == gDanhSachUser[pos].getID() || id2 == gDanhSachUser[pos].getID()) {
				cout << "\t\t\t\t" << ngay << " " << vngay << " " << gio << " " << vgio << " ";
				cout << id1 << " " << t << " " << sotien << " " << loaitiente << " ";
				cout << cho << " " << id2 << endl;
				checkHistory = true;
			}
		}
		else {
			if (id1 == gDanhSachUser[pos].getID()) {
				cout << "\t\t\t\t" << ngay << " " << vngay << " " << gio << " " << vgio << " ";
				cout << id1 << " " << t << " " << sotien << " " << loaitiente << " " << endl;
				checkHistory = true;
			}
		}
	}
	ifile.close();
	if (!checkHistory) {
		cout << "\t\t\t\t" << "Chua co giao dich.\n";
	}
	system("pause");
	menuUser();
}
void doiMaPIN() {
	system("cls");
	string pin, newpin1, newpin2;
labelnhaplaiMaPIN:
	textColor(9);
	cout << "\t\t\t\t* * * * * * * * * *DOI MA PIN* * * * * * * * * *\n";
	cout << "\t\t\t\tNhap ma PIN: ";
	textColor(2);
	getData(pin, 6, 1);
	textColor(9);
	if (pin == gDanhSachUser[pos].getPIN()) {
		cout << "\t\t\t\tNhap ma PIN moi: ";
		textColor(2);
		getData(newpin1, 6, 0);
		textColor(9);
	labelXacNhanPIN:
		cout << "\t\t\t\tXac nhan ma PIN moi: ";
		textColor(2);
		getData(newpin2, 6, 0);
		textColor(9);
		if (newpin1 == newpin2) {
			textColor(4);
			cout << "\t\t\t\tDoi ma PIN thanh cong!\n";
			textColor(9);
			gDanhSachUser[pos].setPIN(newpin1);
			system("pause");
			capNhatTaiKhoan();
			menuUser();
		}
		else {
			textColor(4);
			cout << "\t\t\t\tMa PIN xac nhan khong dung!\n";
			textColor(9);
			goto labelXacNhanPIN;
		}
	}
	else {
		textColor(4);
		cout << "\t\t\t\tMa PIN sai!\n";
		textColor(9);
		cout << "\t\t\t\t-------------------------\n";
		cout << "\t\t\t\t1. Quay lai Menu\n";
		cout << "\t\t\t\t2. Tiep tuc\n";
		cout << "\t\t\t\tMoi chon: ";
		int choice;
		textColor(2);
		cin >> choice;
		textColor(9);
		if (choice == 2) {
			system("cls");
			goto labelnhaplaiMaPIN;
		}
		else if (choice == 1)
			menuUser();
	}
}

//Hàm bổ trợ
bool kiemTraTien(long money)
{
	if (money >= 50000 && money <= (gDanhSachUser[pos].getSoDu() - 50000) && money % 50000 == 0) {
		return true;
	}
	else
		return false;
}
int timID(string id) {
	int vt = -1;
	for (int i = 0; i < gDanhSachUser.size(); i++) {
		if (id == gDanhSachUser[i].getID()) {
			vt = i;
			return vt;
		}
	}
	return vt;
}
void getData(string& s, int size, bool hide) {
	char x = 'a';
	string str;
	while (str.size() < size) {
		x = _getch();
		if (x == 8) {
			if (str.size() != 0) {
				str.pop_back();
				cout << "\b \b";
			}
		}
		else if (x < 48 || x > 57) {
			continue;
		}
		else {
			str.push_back(x);
			cout << x;
			if (hide) {
				cout << "\b \b*";
			}
		}
	}
	cout << endl;
	s = str;
}
void thoiGian()
{
	ofstream ofile("[LichSuID].txt", ios::app);
	struct tm newtime;
	time_t now = time(0);
	localtime_s(&newtime, &now);
	ofile << endl<< "ngay: " << 1900 + newtime.tm_year;
	ofile << "-" << 1 + newtime.tm_mon;
	ofile << "-" << newtime.tm_mday;
	ofile << " gio: " << 1 + newtime.tm_hour << ":";
	ofile << 1 + newtime.tm_min << ":";
	ofile << 1 + newtime.tm_sec<<" ";
	ofile.close();
}
void textColor(int x) {//x la ma mau 0->15
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, x);
}