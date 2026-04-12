#include<bits/stdc++.h>
using namespace std;
using ll = long long;
template<typename T = int>inline T in() { T x; cin >> x; return x; }
#define REP(i,n) for(ll i=0;i<(n);++i)
#define REP1(i,n) for(ll i=1;i<=(n);++i)
#define REPI(i,ini,n) for(ll i=(ini);i<(n);++i)
#define REPC(i,obj) for(auto i:obj)
#define R_UP(a,b) (((a)+(b)-1)/(b))
#define ALL(obj) (obj).begin(),(obj).end()
#define INF 1e9
#define INFL static_cast<ll>(INF)
int main()
{
	while (true)
	{
		int n = in();
		if (n == 0)break;
		vector<int>s(n);
		REP(i, n)s[i] = in();
		sort(ALL(s));
		int sum = 0;
		REP1(i, s.size() - 2)sum += s[i];
		cout << sum / (n - 2) << endl;
	}
}
