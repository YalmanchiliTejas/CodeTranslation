#include<bits/stdc++.h>
using namespace std;

#define             ll  long long
#define            ull  unsigned long long
#define            P_B  push_back
#define            M_P  make_pair
#define             vi  vector<int>
#define             vl  vector<ll>
#define            vii  vector<pair<int, int> >
#define            vll  vector<pair<ll, ll> >
#define            pii  pair<int, int>
#define            pll  pair<ll, ll>
#define         DBG(x)  printf("%s %d\n", #x, x)
#define       DBGLL(x)  printf("%s %lld\n", #x, x)
#define         SCI(x)  scanf("%d",&x)
#define         SCD(x)  scanf("%lf",&x)
#define         SCS(x)  scanf("%s",x)
#define         CLR(x)  memset(x, 0, sizeof(x))
#define        CLRN(x)  memset(x, -1, sizeof(x))
#define        SCLL(x)  scanf("%lld", &x)
#define      FOR(i, n)  for(int i = 0; i < n; i++)
#define  FORR(i, m, n)  for(int i = m; i < n; i++)
#define     SCI2(m, n)  scanf("%d%d", &m, &n)
#define  SCI3(m, n, o)  scanf("%d%d%d",&m, &n, &o)
#define     SCD2(m, n)  scanf("%lf%lf",&m,&n)
#define  SCD3(m, n, o)  scanf("%lf%lf%lf",&m,&n,&o)
#define    SCLL2(m, n)  scanf("%lld%lld", &m, &n)
#define SCLL3(m, n, o)  scanf("%lld%lld%lld",&m, &n, &o)

#define            Mod  1000000007
#define            INF  100000000



int main()
{
	string s;
	int d;
	cin >> s >> d;
	int len = s.size();
	ll dp[105][2];
	CLR(dp);
	dp[0][0] = 1;
	FOR(i, len){
		ll tdp[105][2];
		CLR(tdp);
		FOR(j, d){
			FOR(k, 10){
				if(k == s[i] - '0'){
					tdp[(j+k)%d][0] += dp[j][0];
					tdp[(j+k)%d][0] %= Mod;
				}
				// if( k <= s[i]-'0'){
					if(k < s[i]-'0'){
						tdp[(j+k)%d][1] += dp[j][0];
					}
					tdp[(j+k)%d][1] += dp[j][1];
					tdp[(j+k)%d][1] %= Mod;
					// DBGLL(tdp[(j+k)%d][1]);
					// DBGLL(dp[j][1]);
				// }
				// else{

				// }
			}
		}
		FOR(j, d){
			dp[j][0] = tdp[j][0];
			dp[j][1] = tdp[j][1];
		}
	}
	// DBGLL(dp[0][0]);
	// DBGLL(dp[0][1]);
	ll ans = (dp[0][0] + dp[0][1])%Mod;
	--ans;
	if(ans < 0) ans = Mod - 1;
	printf("%lld\n", ans);
}