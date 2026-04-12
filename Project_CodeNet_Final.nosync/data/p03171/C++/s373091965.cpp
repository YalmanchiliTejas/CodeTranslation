

#include <bits/stdc++.h>
using namespace std;


// M A F I A - M A F I A - M A F I A - M A F I A - M A F I A - M A F I A //

#define int               long long
#define endl              '\n'
#define ff                first
#define ss                second
#define mp                make_pair
#define pb                push_back
#define vii               vector<int> 
#define mii                          map< int, int >
#define msi                          map< string, int > 
#define mib                          map< int, bool > 
#define pii               pair<int,int>
#define vpii              vector< pii >
#define all(v)            v.begin(),v.end()
#define loop(i,s,e)       for(int i=s;i<e;i++)
#define rloop(i,e,s)      for(int i=e;i>=s;i--)
#define mset(a,f)              memset(a,f,sizeof(a))
#define M                 1000000007
#define fastio            ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define prvec(v)          loop(i_u_j,0,v.size())cout << v[i_u_j] <<" "; cout << endl;
#define prarr(arr,n)      loop(i_u_j,0,n)cout << arr[i_u_j] << " "; cout << endl;
#define bug(...)        __f (#__VA_ARGS__, __VA_ARGS__)


template <typename Arg1>
void __f (const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << endl; }
template <typename Arg1, typename... Args>
void __f (const char* names, Arg1&& arg1, Args&&... args)
{
     const char* comma = strchr (names + 1, ',');
     cout.write (names, comma - names) << " : " << arg1 << " | "; __f (comma + 1, args...);
}

// M A F I A - M A F I A - M A F I A - M A F I A - M A F I A - M A F I A //
const int N = 3e5 + 7;
int n;
int arr[N];
int dp[3001][3001];
int getans(int s, int e, bool f, int ans)
{           
      int &mafia = dp[s][e];
      if( mafia != -1 ) return mafia;
      if( s > e ) return ans;
      if(f)
      {
            int a = arr[s] + getans(s+1, e, !f, ans);
            int b = arr[e] + getans(s, e-1, !f, ans);
            return mafia = max(a,b);
      }
      else
      {
            int a = getans(s+1, e, !f, ans) - arr[s];
            int b = getans(s, e-1, !f, ans) - arr[e];
            return mafia = min(a,b);
      }
}

void solve()
{
      cin >> n;
      loop(i,0,n) cin >> arr[i]; 
      mset(dp,-1);
      cout << getans(0,n-1, 1, 0);
}

int32_t main() {
    fastio;

  
  int t = 1; 
  //cin>>t;
  
  while(t--) solve();
  
  


}


// M A F I A - M A F I A - M A F I A - M A F I A - M A F I A - M A F I A //













