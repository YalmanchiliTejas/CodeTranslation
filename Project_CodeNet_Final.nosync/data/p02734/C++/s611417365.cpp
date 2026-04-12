#include "bits/stdc++.h"
using namespace std;

// M A F I A - M A F I A - M A F I A - M A F I A - M A F I A - M A F I A //

#define int                                       long long
#define lop(i,s,e)                                for(int i=s;i<(int)e;i++)
#define rlop(i,e,s)                               for(int i=e;i>=s;i--)
#define prvec(v)                                  lop(R15,0,v.size())cout << v[R15] <<" "; cout << endl;
#define prarr(arr,s1,e1)                          lop(R15,s1,e1)cout << arr[R15] << " "; cout << endl;

#define endl                                      '\n'
#define ff                                        first
#define ss                                        second
#define pii                                       pair<int,int>

#define pb                                        push_back
#define all(v)                                    v.begin(),v.end()         

#define bug(...)                                  __f (#__VA_ARGS__, __VA_ARGS__)
#define rtn                                       if(0)return;
template <typename Arg1>
void __f (const char* name, Arg1&& arg1) { rtn cout << name << " : " << arg1 << endl; }
template <typename Arg1, typename... Args>
void __f (const char* names, Arg1&& arg1, Args&&... args)
{     rtn 
     const char* comma = strchr (names + 1, ',');
     cout.write (names, comma - names) << " : " << arg1 << " | "; __f (comma + 1, args...);
}

// M A F I A - M A F I A - M A F I A - M A F I A - M A F I A - M A F I A //

inline void INP();
const int N = 3e6 + 7, M = 998244353, inf = INT_MAX;
const long long INF = LLONG_MAX;

int n, Q, s;
int arr[N+2];
int dp[3002][3002];

int subset(int id, int sum   )
{     
      if(sum < 0) return 0;
      if(!sum) return id + 1;
      if( id == 0 ) return 0;

      int &mafia = dp[id][sum];
      if( mafia != -1 ) return mafia;

      int a = 0, b = 0;
      a = subset(id-1, sum);
      b = subset(id-1, sum-arr[id]);

      return mafia = (a+b)%M; 
}


void solve()
{
      cin >> n >> s;
      lop(i,1,n+1) cin >> arr[i];
      int ans = 0;
      memset(dp, -1, sizeof dp);
      lop(i,1,n+1) ans += subset(i,s), ans %= M;
      cout << ans;
}


int32_t main()
{
      
      ios_base::sync_with_stdio(0);   cin.tie(0);   cout.tie(0);
     // INP(); 
      int t = 1;
      //cin >> t;
      while(t--) solve();

}











inline void INP()
{
      #ifndef ONLINE_JUDGE
          freopen("input.txt",  "r",  stdin);
          freopen("output.txt", "w", stdout);
      #endif
}


// M A F I A - M A F I A - M A F I A - M A F I A - M A F I A - M A F I A //




