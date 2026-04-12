#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define len(n) (int)n.length()
#define pb push_back
#define ll long long
#define make_pair mkp
#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define ALL(v) (v).begin(), (v).end()
#ifdef DBGPRT
#define dbg(n) cerr << "//" << #n << ":" << n <<endl
#else
#define dbg(n) ;
#endif
typedef pair<ll, ll> LLARR;
#define INF 999999999
const double PI = 3.1415926535897932384626433832795;

int main()
{
	ios::sync_with_stdio(false);
	int n,m;
	cin >> n >> m;
	
	bool r[100][100] = {false};
	REP(i, m)
	{
		int a,b;
		cin >> a >> b;
		r[a][b] = true;
		r[b][a] = true;
	}
	stack<int> st;
	st.push(1);
	vector<bool> f(100, false);
	stack<vector<bool> > mem;
	mem.push(f);
	
	int ans = 0;
	while (!st.empty())
	{
		int now = st.top(); st.pop();
		dbg(now);
		vector<bool> nowf = mem.top(); mem.pop();
		
		nowf[now] = true;
		bool bAll = true;
		for(int i = 1; i <=n; i++)
		{
			if (r[now][i])
			{
				if (!nowf[i])
				{
					st.push(i);
					mem.push(nowf);
					bAll=false;
				}
			}
		}
		if(bAll)
		{
			for(int i = 1; i <= n; i++)
			{
				if (!nowf[i])
				{
					bAll = false;
					break;
				}
			}
		}
		if(bAll)
		{
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}