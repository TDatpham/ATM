#pragma once
#include <iostream>
#include <vector>

using namespace std;


class User {
	string _strID,_strPIN, _strTen, _strLoaiTienTe;
	long _lSoDu;
	bool _bUnlock;
public:
	User() {
		_strPIN = "123456";
		_bUnlock = true;
	}
	void setUser(string ID, string ten, long soDu, string loaiTienTe, bool unlock){
		_strID = ID;
		_strTen = ten;
		_lSoDu = soDu;
		_strLoaiTienTe = loaiTienTe;
		_bUnlock = unlock;
	}

	string getID(){
		return _strID;
	}
	string getPIN(){
		return _strPIN;
	}
	string getTen() {
		return _strTen;
	}
	long getSoDu() {
		return _lSoDu;
	}
	string getLoaiTienTe() {
		return _strLoaiTienTe;
	}
	bool getUnLock() {
		return _bUnlock;
	}

	void setID(string id) {
		_strID = id;
	}
	void setPIN(string pin){
		_strPIN = pin;
	}
	void setTenTaiKhoan(string ten) {
		_strTen = ten;
	}
	void setSoDu(long soDu) {
		_lSoDu = soDu;
	}
	void setLoaiTienTe(string loaiTienTe) {
		_strLoaiTienTe = loaiTienTe;
	}
	void setUnlock(bool unclock) {
		_bUnlock = unclock;
	}

	friend istream& operator >> (istream& in, User& u)
	{
		in >> u._strID >> u._strPIN >> u._strTen >> u._lSoDu;
		cin.ignore();
		in >> u._strLoaiTienTe;
		u._bUnlock = true;
		return in;
	}

	friend ostream& operator << (ostream& out, User u)
	{
		out << u._strID << endl;
		out << u._strPIN << endl;
		out << u._strTen << endl;
		out << u._lSoDu << " " << u._strLoaiTienTe << endl;
		out << u._bUnlock;
		return out;
	}

};