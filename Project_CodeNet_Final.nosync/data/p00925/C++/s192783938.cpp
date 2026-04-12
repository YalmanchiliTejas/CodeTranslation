#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
template<class T>
using Table = vector<vector<T>>;
const ld eps=1e-9;

//// < "D:\D_Download\Visual Studio 2015\Projects\programing_contest_c++\Debug\a.txt"
int a = 0;
string st;
long long int getnum() {
	long long int num = 0;
	while (isdigit(st[a])) {
		num = num * 10 + st[a] - '0';
		a++;
	}
	return num;
}

long long int getexpr0() {
	long long int num(getnum());
	while (a != st.size()) {
		if (st[a] == '+') {
			a++;
			long long int bnum = getnum();
			num += bnum;
		}
		else {
			a++;
			long long int bnum = getnum();
			num *= bnum;
		}
	}
	return num;

}
long long int getkake() {
	long long int num(getnum());
	while (a != st.size()) {
		if (st[a] == '*') {
			a++;
			long long int bnum = getnum();
			num *= bnum;
		}
		else {
			return num;
		}
	}
	return num;

}
long long int getplus() {
	long long int num(getkake());
	while (a != st.size()) {
		if (st[a] == '+') {
			a++;
			long long int bnum = getkake();
			num += bnum;
		}
		else {
			assert(false);
		}
	}
	return num;

}
int main() {cin >> st;
a = 0;
int n; cin >> n;
   long long  int aa=getexpr0();
   a = 0;
	long long int bb = getplus();
	if (aa == n&&bb == n) {
		cout << "U" << endl;
	}
	else if (aa == n) {
		cout << "L" << endl;
	}
	else if (bb == n) {
		cout << "M" << endl;
	}
	else {
		cout << 'I' << endl;
	}
	return 0;
}