//I am so vegetable
#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define _for(i,a,b) for(ll i = (a);i<(b);++i)
#define _defor(i,a,b) for((i) = (a);(i)<(b);++i)
#define _rfor(i,a,b) for(int i = (a);i>(b);--i)
#define _sfor(p,st) for(auto &p:st)
//#define _LOCAL_
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll N = 105;
const int MOD = 998244353;
const double exps = 1e-6;
int main() {
#ifdef _LOCAL_
	ifstream cin("E:\\acm dream\\in.txt");
	ofstream cout("E:\\acm dream\\out.txt");
#endif
	//srand((unsigned)time(nullptr));
	FIO;
	string s; cin >> s;
	if (s[0] == s[1] && s[1] == s[2])cout << "No\n";
	else cout << "Yes\n";
	return 0;
}