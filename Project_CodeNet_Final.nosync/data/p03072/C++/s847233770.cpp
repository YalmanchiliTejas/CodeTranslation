#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 1e9
#define ALL(v) (v).begin(), (v).end()
using namespace std;
typedef long long ll;
ll GCD(ll a,ll b){return b?GCD(b,a%b):a;}
ll LCM(ll a,ll b){return (a*b)/GCD(a,b);}
 
//const int dx[] = {1, 0, -1, 0, 1, -1, -1, 1};
//const int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};

int main()
{
	int n;
	cin >> n;
	int h[n];
	bool ck = 1;
	int ans = 0;
	REP(i, n) cin >> h[i];
	REP(i, n){
		ck = 1;
		REP(j, i){
			if (h[j] > h[i]) ck = 0;
		}
		ans += ck;
	}

	cout << ans << endl;

}
