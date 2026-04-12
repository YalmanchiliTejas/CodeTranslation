#include<iostream>
#include<string>
using namespace std;

int main() {
	char S[20];
	string T;
	string p;
	string Q;
	int a = 0;
	int A = 0;
	int b = 0;
	int B = 0;
	int c = 0;
	int C = 0;
	int q, w, z;
	int n = 0;
	int x = 0;
	int y = 0;
	int ans = 0;
	cin >> a >> b >> c;
	n = a * 100 + b * 10 + c;
	if (n % 4 == 0) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}
}