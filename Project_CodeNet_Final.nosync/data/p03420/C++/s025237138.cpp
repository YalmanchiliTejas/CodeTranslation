#include<bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
double eps=1e-8;
ll mod=1e9+7;
ll inf=1e9;
priority_queue<P,vector<P>,greater<P> > pq;
 
int main(){
  ll n,k;
  cin>>n>>k;
  ll ans=0;
  for(ll b=k+1;b<=n;b++){
    ans+=n/b*(b-k);
    ans+=max(0LL,n%b-k+(k==0?0:1));
  }
  
  cout<<ans<<endl;
  return 0;
}