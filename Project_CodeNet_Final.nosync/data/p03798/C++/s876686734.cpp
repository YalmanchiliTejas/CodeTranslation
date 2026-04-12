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
vector<bool> a(100005, false);
	int n;
bool isSame(int pos)
{
	if (pos==0)
		return a[n-1] == a[1];
	if (pos==n-1)
		return a[n-2] == a[0];
	return a[pos-1] == a[pos+1];
}

int main()
{
	ios::sync_with_stdio(false);


	cin >> n;
	string s;
	cin >> s;
	
	bool t[2] = {true, false};

	REP(j,2)
	{
		REP(k,2)
		{
			a[0] = t[j];
			a[1] = t[k];

			for(int i = 2; i < n; i++)
			{
				if(s[i-1] == 'o')
					if (a[i-1])
					{
						a[i] = a[i-2];
					}
					else
					{
						a[i] = !a[i-2];
					}
				else
					if (a[i-1])
					{
						a[i] = !a[i-2];
					}
					else
					{
						a[i] = a[i-2];
					}
			}
			REP(i, n)
			{
				dbg(a[i]);
			}
			dbg("=--");
			bool ok = true;
			for (int i = 0; i < n; i++)
			{
				if (a[i])
					if ((isSame(i) && (s[i] == 'o')) ||
					((!isSame(i) && (s[i] == 'x'))))
					{
						continue;
					}
					else
					{
						ok = false;
						break;
					}
				else
					if ((!isSame(i) && (s[i] == 'o')) ||
					((isSame(i) && (s[i] == 'x'))))
					{
						continue;
					}
					else
					{
						ok = false;
						break;
					}
				
			}
			if (ok)
			{
				REP(i,n)
				{
					cout << (a[i] ? 'S' : 'W');
				}
				cout << endl;
				return 0;
			}
		}
	}
	cout << -1 << endl;
	return 0;
}