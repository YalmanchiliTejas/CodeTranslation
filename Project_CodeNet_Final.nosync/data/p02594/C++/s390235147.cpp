#include <bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
#define dout cout
#define debug() if (true)
#define dvout(v) vout(v)
#else
#define dout if (false) cout
#define debug() if (false)
#define dvout(v) if(false) vout(v)
#endif

#define rep(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define all(x) (x).begin(), (x).end()
#define vout(v)           \
	for (auto &i : v)     \
	{                     \
		cout << i << " "; \
	}                     \
	cout << "\n"; //配列出力
#define vec(v, n) vector<int> v(n, 0);
#define vecll(v, n) vector<ll> v(n, 0);
#define vecvec(v,n,m) vector<vector<int>> v(n, vector<int>(m));
#define vin(v)        \
	for (auto &i : v) \
		cin >> i; //配列入力

#define mod (int)(1e9+7)
typedef long long ll;
typedef unsigned long long ull;
#define next asdnext
#define prev asdprev
#define _n "\n"
#define _n2 "\n\n"
#define _t "\t"

//	LLONG_MAX 9.2*1e18	9223372036854775807LL = (2^63)-1
//	INT_MAX 2.1*1e9 2147483647 = (2^31)-1
//	O(1e8) 1.2sec

void Main()
{
	int X;
	cin>>X;
	if(X>=30)cout<<"Yes"<<_n;
	else cout<<"No"<<_n;
}


void Test();
int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	cout << std::fixed << std::setprecision(15);
	Main();
	return 0;
}
