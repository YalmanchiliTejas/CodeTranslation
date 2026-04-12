
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
const int N = 1e5 + 7;
string str;
int n, D;
int arr[N], dp[N][2][101];
int getans(int idx, int f, int rem)
{     
      int &mafia = dp[idx][f][rem];
      if( mafia != -1 ) return mafia;
      if( idx == n )   return (rem == 0);
      
      int mxd = str[idx] - '0';
      if(f) mxd = 9;

      int ans = 0;
      for(int i = 0; i <= mxd; i += 1)
      {
            int nf = f;
            if( i < mxd ) nf = 1;
            ans += getans( idx+1, nf, (rem + i)%D );
            ans %= M;
      }
      return mafia = ans;
}

void solve()
{
     cin >> str >> D;
     n = str.length();
     mset(dp,-1);
     int ans = getans(0,0,0) - 1;
     if( ans == -1 ) ans = M - 1;
     cout << ans;

}

int32_t main() {
    fastio;

  


  int t = 1; 
  //cin>>t;
  
  while(t--) solve();
  
  


}


// M A F I A - M A F I A - M A F I A - M A F I A - M A F I A - M A F I A //













