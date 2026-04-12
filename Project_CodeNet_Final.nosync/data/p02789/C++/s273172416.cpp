#include<bits/stdc++.h>
using namespace std;

#define int long long
#define w cout
#define e '\n'
#define sz(x) (int)x.size()
template<class T, class U> inline istream& operator>>(istream& str, pair<T, U> &p) { return str >> p.first >> p.second; }
template<class T> inline istream& operator>>(istream& str, vector<T> &a) { for (auto &i : a) str >> i; return str; }

const int N = 1e6 + 10 , mod = 998244353;


signed main() {
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n , m ;cin >> n >> m;
	if(n ==m ) cout << "Yes";
	else w << "No";
}

