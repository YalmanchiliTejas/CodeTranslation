
#include<bits/stdc++.h>
#define ll          long long
#define pb          push_back
#define c(P)        cout<<P<<"\n"
#define pii         pair<ll,ll>
#define mi          map<ll,ll>
#define mii         map<pii,ll>
#define F           first
#define S           second
#define mem(a,val)  memset(a,val,sizeof(a))
#define fr(i,x,n)   for(ll i=x;i<n;i++)
#define frr(i,x,n)  for(ll i=n-1;i>=x;i--)
using namespace std;


const ll N   =  500005;
const ll mod = 1e9 + 7;



void solve(){

  ll x=0,y=0,c=0,ans=0;
  ll n,m,k;
  string s;
  cin>>s;

  for (ll i = 0; i < s.size(); ++i)
  {
   if(s[i]=='A')x++;
   else y++;
  }
  if(x==0 or y==0){
  	c("No");
  }
  else c("Yes");
  
}

signed main(){
     
  ios_base::sync_with_stdio(false);   
  cin.tie(NULL);
  ll T=1;
  //cin>>T;
  while(T--){
  solve();
  }
  return 0;
}
