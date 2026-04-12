            #pragma GCC optimize("O3")
            #pragma comment(linker, "/stack:200000000")
            #pragma GCC optimize("unroll-loops")
             
            #include <algorithm>
            #include <bitset>
            #include <cassert>
            #include <chrono>
            #include <cmath>
            #include <complex>
            #include <cstdio>
            #include <cstdlib>
            #include <cstring>
            #include <ctime>
            #include <deque>
            #include <functional>
            #include <iomanip>
            #include <iostream>
            #include <iterator>
            #include <limits>
            #include <climits>
            #include <list>
            #include <map>
            #include <numeric>
            #include <queue>
            #include <random>
            #include <ratio>
            #include <set>
            #include <sstream>
            #include <stack>
            #include <string>
            #include <unordered_map>
            #include <unordered_set>
            #include <utility>
            #include <vector>
            using namespace std;
             
            typedef long long ll;
            typedef long double ld;
            #define int ll
            #define double ld
            #define pb push_back
            #define mp make_pair
            #define REP(i,n) for (int i = 0; i < n; i++)
            #define loop(i,n) for (int i = 0; i < n; i++)
            #define FOR(i,a,b) for (int i = a; i < b; i++)
            #define REPD(i,n) for (int i = n-1; i >= 0; i--)
            #define FORD(i,a,b) for (int i = a; i >= b; i--)
            #define remax(a,b) a = max(a,b)
            #define remin(a,b) a = min(a,b)
            #define mem(a, b) memset(a, b, sizeof a)
            #define append push_back
            #define all(v) v.begin(),v.end()
            #define F first
            #define S second
            #define print(x) cout << (x) << endl
            #define PRECISION(x) cout << fixed << setprecision(x)
            #define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
            
            const double PI=acos(-1);
            const int MOD = 1000000007;
            const int FMOD = 998244353;
            const double eps = 1e-9;
             
            mt19937 RNG(chrono::steady_clock::now().time_since_epoch().count()); 
 
 
 int dp[10005][105][2][2];
 string k;
 int d;
 int solve(int pos,int tight,int st,int sum)
 {
 	if(pos==k.size())
 	{
 		if(sum==0 && st)
 		return 1;
 		return 0;
	 }
	 if(dp[pos][sum][tight][st]!=-1)
	 {
	 	return dp[pos][sum][tight][st];
	 }
	int up=(tight)?(k[pos]-'0'):9;
	
	int ans=0;
	ans=(ans+solve(pos+1,tight&(up==0),st,sum))%MOD;
	for(int i=1;i<=up;i++)
	{
		ans=(ans+solve(pos+1,tight&(up==i),1,(sum+i)%d))%MOD;
	}
	return dp[pos][sum][tight][st]=ans;
 }
signed main(){

	
	cin>>k>>d;
	mem(dp,-1);
	cout<<solve(0,1,0,0);
}
			