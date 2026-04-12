#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef std::pair<int, int> ii;
typedef std::pair<int, ii> iii;
typedef std::vector<int> vi;
typedef std::vector<vi> vvi;
typedef std::vector<ii> vii;
typedef std::vector<iii> viii;
const int INF=10000000;
#define pb(a) push_back(a)
#define m0(x) memset(x,-1,sizeof(x))
#define print(x) cout<<x<<endl;
#define pe(x) cout<<x<<" ";
#define lb(v,n) lower_bound(v.begin(), v.end(), n);
#define ub(v,n) upper_bound(v.begin(), v.end(), n);
#define all(x) (x).begin(), (x).end()
const ll mod=1e9+7;
ll fact[1005];
ll rfact[1005];
ll memo[1005][1005];
int N,A,B,Ca,D;

ll pow(ll base, ll exp) {
  if(exp==0) return 1;
  if(exp&1) return (base*pow(base,exp-1))%mod;
  else return pow((base*base)%mod,exp/2);
}


ll inv(ll n){ return pow(n,mod-2); }

void initialize(){
  fact[0] = 1;
  for(ll n = 1; n <= N; n++)
    fact[n] = (fact[n-1]*n)%mod;
}


ll dp(ll n, ll curr){
  //cerr<<n<<" "<<curr<<endl;
  if (n==0) return 1;
  else if (n<0 or curr>B) return 0;
  else {
    if (memo[n][curr]==-1){
      ll ans=dp(n,curr+1);

      for (ll count=Ca; count<=D and count*curr<=n; count++){
        
          ll num=fact[n];
          ll denom=(pow(fact[curr],count)*fact[n-count*curr])%mod;
          denom=(denom*fact[count])%mod;
          denom=inv(denom);
 
          ll temp=dp(n-count*curr,curr+1);
          temp=(temp*num)%mod;
          temp=(temp*denom)%mod;
 
          ans=(ans+temp+mod)%mod;
      }
    memo[n][curr]=ans;
    }
    return memo[n][curr];
  }

}





int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  
  memset(memo,-1,sizeof(memo));
  cin >> N >> A >> B >> Ca >> D;
  initialize();
  cout<<dp(N,A);
  
  

  



}
