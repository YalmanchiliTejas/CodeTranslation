#include<iostream>
#include<cmath>
#include<algorithm>
#include <cassert>
#include<string>
using namespace std;
int main(){
	int a = 0, b = 0, c=0, d[100000], e[100000],f=0,g=0,h=0, count = 0;
	char ac,uc[100000];
	string manji,gage;
	cin >> a>>b>>c;
	if ((b * 10 + c) % 4 == 0) {
		cout << "YES" << endl;
	}
	else { cout << "NO" << endl; }
	return 0;
}