#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define len(n) (int)n.length()
#define pb push_back
#define ll long long
#define make_pair mkp
#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n-1;i >= 0;i--)
#define ALL(v) (v).begin(), (v).end()
#ifdef DBGPRT
#define dbg(n) cerr << "//" << #n << ":" << n <<endl
#else
#define dbg(n) ;
#endif
typedef pair<ll, ll> LLARR;
#define INF 999999999
const double PI = 3.1415926535897932384626433832795;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main()
{
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	int ap[n]['z'-'a'+1] = {0};
	REP(i,n)
	{
		string t; cin >> t;
		REP(j, len(t))
		{
			// dbg(t[j]-'a');
			ap[i][t[j]-'a']++;
		}
	}

	
	REP(i,'z'-'a'+1)
	{
		int m = INF;
		REP(j, n)
		{
			if(ap[j][i] > 0)
			{
				m = min(m, ap[j][i]);
			}
			else
			{
				m = INF;
				break;
			}
		}
		if (m != INF)
		{
			REP(k,m)
			{
				cout << (char)((int)'a' + i);
			}
		}
	}
	cout << endl;
	
	return 0;
}