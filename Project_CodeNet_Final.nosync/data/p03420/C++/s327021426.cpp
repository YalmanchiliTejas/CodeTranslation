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
#define DBG_N(hoge) cerr<<"!"<<" "<<(hoge)<<endl;
#define DBG cerr<<"!"<<endl;
#define BITLE(n) (1LL<<((ll)n))
#define BITCNT(n) (__builtin_popcountll(n))
#define SUBS(s,f,t) ((s).substr((f)-1,(t)-(f)+1))
#define ALL(a) (a).begin(),(a).end()
using namespace std;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll n,k;cin>>n>>k;
  ll ans=0;
  for(int i=k+1;i<=n;i++){
    ll num=(n+1)/i*i;
    if(k==0){num=n/i*i;}
    ans+=num/i*(i-k);
    if(k==0){ans+=max(0LL,((i-k)-(num+i-n)));}
else
    ans+=max(0LL,((i-k)-((num+i)-n-1)));
  }
  cout<<ans<<endl;
  return 0;
}
