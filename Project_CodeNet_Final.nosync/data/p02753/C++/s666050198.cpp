#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using p = pair<ll, ll>;
using V = vector<int>;
using VV = vector<vector<int>>;
using VVV = vector<vector<vector<int>>>;
using VL = vector<ll>;
using VVL = vector<vector<ll>>;
using VVVL = vector<vector<vector<ll>>>;
using Graph = VV;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
int Inf = (1 << 30);
ll inf = (1LL << 60);
const int MOD = 1e9 + 7;
const int T = 1000000001;
int main() {
	string s;
	cin >> s;
	set<char> st;
	for (int i = 0; i < 3; i++)st.insert(s[i]);
	if (st.size() == 2) cout << "Yes";
	else cout << "No";
	return 0;
}