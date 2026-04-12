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
#define BITLE(n) (1LL<<((ll)n))
#define BITCNT(n) (__builtin_popcountll(n))
#define SUBS(s,f,t) ((s).substr((f)-1,(t)-(f)+1))
#define ALL(a) (a).begin(),(a).end()
using namespace std;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll n,l,r;
  while(cin>>n>>l>>r,n+l+r){
    vi A(n);
    for(auto &a:A)cin>>a;
    ll ans=0;
    for(int i=l;i<=r;i++){
      bool fl=true;
      for(int j=0;j<n;j++){
	if(i%A[j] == 0){
	  fl = false;
	  if(j%2==0)ans++;
	  break;
	}
      }
      if(fl){
	if(n%2==0)
	  ans++;
      }
    }
    cout<<ans<<endl;
  }
  return 0;
}

