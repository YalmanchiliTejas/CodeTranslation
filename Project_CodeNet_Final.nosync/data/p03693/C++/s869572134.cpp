#include<cstdio>
#include<iostream>
#include<queue>
#include<string>
#include<vector>
#include<random>
#include<fstream>
#include<map>
using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	if ((b * 10 + c) % 4 == 0) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
}
