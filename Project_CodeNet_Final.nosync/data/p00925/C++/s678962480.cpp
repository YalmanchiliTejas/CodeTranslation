#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<random>
#include<map>
#include<set>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;
const ll INF = (ll)1000000007 * 1000000007;
const double EPS = 1e-9;
typedef pair<int, int> P;
typedef unsigned int ui;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
int main() {
	string s; int n;
	cin >> s >> n;
	int len = s.length();
	vector<int> t;
	rep(i, len) {
		if (s[i] == '+' || s[i] == '*')t.push_back(0);
		else t.push_back(s[i] - '0');
	}
	int m, l; m = 0; l = t[0];
	rep(i, len) {
		if (s[i] == '+') {
			m += t[i - 1];
			l += t[i + 1];
		}
		else if(s[i]=='*'){
			l *= t[i + 1];
			t[i + 1] *= t[i-1];
		}
	}
	m += t[len - 1];
	if (m == n && l == n) {
		cout << "U" << endl;
	}
	else if (m == n) {
		cout << "M" << endl;
	}
	else if (l == n) {
		cout << "L" << endl;
	}
	else {
		cout << "I" << endl;
	}
	return 0;
}
