#include<bits/stdc++.h>
#define INF 1e9
#define llINF 1e18
#define MOD 1000000007
#define pb push_back
#define mp make_pair 
#define F first
#define S second
#define ll long long
#define ull unsigned long long
#define vi vector<ll>
#define vvi vector<vi>
#define DBG_N(hoge) cerr<<" "<<(hoge)<<endl;
#define DBG cerr<<"!"<<endl;
#define BITLE(n) (1LL<<((ll)n))
#define BITCNT(n) (__builtin_popcountll(n))
#define SUBS(s,f,t) ((s).substr((f)-1,(t)-(f)+1))
#define ALL(a) (a).begin(),(a).end()
using namespace std;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll n;cin>>n;
  vi A(n);
  map<ll,ll>MP;
  vi prime;
  prime.pb(2);
  for(ll i=3;i<=sqrt(1e9+10);i+=2){
    bool hoge=true;
    for(ll j=2;j<=sqrt(i);j++){
      if(i%j==0){
	hoge=false;
	break;
      }
    }
    if(hoge)prime.pb(i);
  }
  ll ans=0;
  for(int i=0;i<n;i++){
    ll a;cin>>a;
    ll ori=a;
    ll now=0;
    set<ll>se;
    while(now<prime.size()&&a>1){
      if(a%prime[now]==0){a/=prime[now];se.insert(prime[now]);}
      else now++;
    }
    if(a>1)se.insert(a);
    for(auto aa:se){
      MP[aa]+=ori;
    }
  }
  for(auto a:MP){
    //  cout<<a.F<<" "<<a.S<<endl;
    ans=max(ans,a.S);
  }
  cout<<ans<<endl;
  return 0;
}

