#include<iostream>
#include<string>
#include<vector>
#define int long long
#define stoi stoll
using namespace std;

signed main() {
	string a; cin >> a;
	int b; cin >> b;
	vector<string>c;
	string e;
	for (char d : a) {
		if (d == '+' || d == '*') { c.push_back(e); e = ""; e += d; c.push_back(e); e = ""; }
		else e += d;
	}
	c.push_back(e);
	vector<string>x, y; x = y = c;
	int sum = stoi(x[0]);
	for (int i = 1; i<x.size(); i += 2) {
		if (x[i] == "+")sum += stoi(x[i + 1]);
		else sum *= stoi(x[i + 1]);
	}
	y.push_back("+");
	int S = 0;
	int J = 1;
	for (string t : y) {
		if (t == "+") { S += J; J = 1; }
		else if (t != "*")J *= stoi(t);
	}
	if (S == b) {
		if (sum == b) {
			puts("U");
		}
		else {
			puts("M");
		}
	}
	else {
		if (sum == b) {
			puts("L");
		}
		else {
			puts("I");
		}
	}
}