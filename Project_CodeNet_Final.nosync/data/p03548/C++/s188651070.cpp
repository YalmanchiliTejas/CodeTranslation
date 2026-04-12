#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(const string &a,const string &b){
	int i = 0;
	while(a[i] == b[i]){
		i++;
	}
	if(i == a.length()) return 0;
	return a[i] < b[i];
}
bool isvalidnum(const int money, vector<bool> hatenum){
	int m = money;
	int nownum;
	while(m>0){
		nownum = m%10;
		if (hatenum[nownum]) return false;
		m = (m-nownum)/10;
	}
	return true;
}

int main () {
	int X, Y, Z;
	cin >> X >> Y >> Z;
	cout << (X-Z)/(Y+Z);

	return 0;
}