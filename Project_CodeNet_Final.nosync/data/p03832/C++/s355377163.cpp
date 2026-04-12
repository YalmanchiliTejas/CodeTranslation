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
int N,mingroup,maxgroup,minsize,maxsize;
ll factorial[1005];
ll rfactorial[1005];

ll pow(ll base, ll exp) {
  if(exp==0) return 1;
  if(exp&1) return (base*pow(base,exp-1))%mod;
  else return pow((base*base)%mod,exp/2);
}
 


void start(){
  ll temp=1;
  factorial[0]=1;
  for (int i=1; i<=1000; i++){
    temp=(temp*i)%mod;
    factorial[i]=temp;
  }
}





ll inverse(ll curr){
  return pow(curr,mod-2);
}

ll memo[1001][1001];


ll DP(ll remaining, ll current){
  //cerr<<remaining<<" "<<current<<endl;
  if (remaining==0) return 1;
  else if (remaining<0 or current>maxgroup) return 0;
  else {
    if (memo[remaining][current]==-1){
      ll ans=DP(remaining,current+1);
      
      for (ll i=minsize; i<=maxsize and i*current<=remaining; i++){
          
          ll num=factorial[remaining];
          ll denom=(pow(factorial[current],i)*factorial[remaining-i*current])%mod;
          denom=(denom*factorial[i])%mod;
          denom=inverse(denom);

          ll temp=DP(remaining-i*current,current+1);
          temp=(temp*num)%mod;
          temp=(temp*denom)%mod;

          ans=(ans+temp+mod)%mod;
          //ans=(ans+DP(remaining-i*current,current+1))%mod;
        
      }
      memo[remaining][current]=ans;

    }
    return memo[remaining][current];
  }





}




int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  start();
  m0(memo);
  cin >> N >> mingroup >> maxgroup >> minsize >> maxsize;
  cout<<DP(N,mingroup)<<endl;

  

  



}
