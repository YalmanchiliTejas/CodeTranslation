//F5で実行 Shift+F5で停止
//F9でブレークポイント
#include<cmath>
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()
#pragma GCC optimize ("-O3")
using namespace std; void _main(); int main() { cin.tie(0); ios::sync_with_stdio(false); _main(); }
typedef long long ll; const int inf = INT_MAX / 2; const ll infl = 1LL << 60;
template<class T>bool chmax(T &a, const T &b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b < a) { a = b; return 1; } return 0; }
//---------------------------------------------------------------------------------------------------
//Ctrl+PageUpで上部の大半を選択できる
// 1e18 = 10の18乗

string S;
string ans = "No";

void _main() {
	cin >> S;


	rep(i,1,S.length()) {
		if (S[i - 1] != S[i]) {
			ans = "Yes";
		}
	}

	cout << ans << endl;
}