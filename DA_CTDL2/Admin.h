#pragma once
#include <iostream>
#include "User.h"
#include <vector>
#include <fstream>

using namespace std;

class Admin {

	string _strID, _strPIN;
public:
	
	Admin(string id, string pin) {
		_strID = id;
		_strPIN = pin;
	}
	void getAdmin(string id, string pin) {
		_strID = id;
		_strPIN = pin;
	}
	string getID() {
		return _strID;
	}
	string getPIN() {
		return _strPIN;
	}
	void setID(string id) {
		_strID = id;
	}
	void setPIN(string pin) {
		_strPIN = pin;
	}

	friend istream& operator >> (istream& in, Admin& a) {
		in >> a._strID >> a._strPIN;
		return in;
	}

};
