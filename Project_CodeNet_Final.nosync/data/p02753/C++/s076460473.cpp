#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
#include<vector>
#define REP(i,m,n) for(int i=(int)(m);i<(int)(n);i++)
#define rep(i,n) REP(i,0,n)
#define ll long long

using namespace std;

string s;

int main() {
	cin >> s;
	if (s == "AAA" || s == "BBB") {
		cout << "No" << endl;
	}
	else cout << "Yes" << endl;

	return 0;
}
