#include <bits/stdc++.h>
using namespace std;



typedef unsigned long ul;
typedef unsigned long long ull;
typedef long long ll;
typedef vector<ll> vint;
typedef vector< vector<ll> > vvint;
typedef vector< vector< vector<ll> > > vvvint;
typedef vector<string> vstring;
typedef vector< vector<string> > vvstring;
typedef vector<char> vchar;
typedef vector< vector<char> > vvchar;
typedef vector<long double> vdouble;
typedef vector< vector<long double> > vvdouble;
typedef vector< vector< vector<long double> > > vvvdouble;
typedef pair<ll,ll> pint;
typedef vector<pint> vpint;
typedef vector<bool> vbool;

#define rep(i,n) for(ll i=0;i<n;i++)
#define repf(i,f,n) for(ll i=f;i<n;i++)
#define repr(i,n) for(ll i=n-1;i>=0;i--)
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define ALL(obj) (obj).begin(), (obj).end()
// #define LLONG_MAX 9223372036854775806
#define vmax(vec) *max_element(vec.begin(), vec.end())
#define vmin(vec) *min_element(vec.begin(), vec.end())
#define vsort(vec) sort(vec.begin(), vec.end())
#define vsortgr(vec) sort(vec.begin(), vec.end(), greater<ll>())
#define MOD 1000000007
// #define MOD 998244353
// #define MOD LLONG_MAX
const double PI=3.14159265358979323846;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }




int dy[]={0, 0, 1, -1};
int dx[]={1, -1, 0, 0,};




void printv(vint &v){
  for(auto e:v) cout<<e<<" ";
  cout<<endl;
}


int main() {


  cout<<fixed<<setprecision(10);

  string n; cin>>n;

  ll keta = n.size();


  ll kk; cin>>kk;

  ll dp[keta+1][2][5];
  rep(i,keta+1)rep(j,2)rep(k,5) dp[i][j][k] = 0;

  dp[0][0][0] = 1;

  rep(i,keta){

    ll x = n[i] - '0';

    if(x == 0){
      // 00
      rep(k,4){
        dp[i+1][0][k] += dp[i][0][k];
      }
  

      // 01
      // rep(k,4){
      //   dp[i+1][1][k] += dp[i][0][k]; // k -> k
      // }

      // 11
      rep(k,4){
        dp[i+1][1][k] += dp[i][1][k]; // k -> k
        dp[i+1][1][k+1] += dp[i][1][k]*9; // k -> k+1
      }

    }else{
      // 00
      rep(k,4){
        dp[i+1][0][k+1] += dp[i][0][k];

        // dp[i+1][0][k] += dp[i][0][k]; // k -> k
        // dp[i+1][0][k+1] += dp[i][0][k]*(x-1); // k -> k+1
      }

      // 01
      rep(k,4){
        dp[i+1][1][k] += dp[i][0][k];
        dp[i+1][1][k+1] += dp[i][0][k]*(x-1); // k -> k+1
      }

      // 11
      rep(k,4){
        dp[i+1][1][k] += dp[i][1][k]; // k -> k
        dp[i+1][1][k+1] += dp[i][1][k]*9; // k -> k+1
      }

    }




  }


  cout<<dp[keta][0][kk] + dp[keta][1][kk]<<endl;
}

//
