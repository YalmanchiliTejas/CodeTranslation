#include<bits/stdc++.h>
using namespace std;

#define w cout
#define e '\n'
#define int long long
#define sz(x) (int)x.size()
template<class T> inline istream& operator>>(istream& str, vector<T> &a) { for (auto &i : a) str >> i; return str; }

const int N = 1e6;

signed main() {
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	string s;cin >> s;
	int c = 0;
	for(char i : s) {
		if(i == 'A') c++;
	}
	if(c == 1 || c == 2) w << "Yes" ;
	else w << "No";
}
