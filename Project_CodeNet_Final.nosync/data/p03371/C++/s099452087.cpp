#include<bits/stdc++.h>
#include <math.h>
using namespace std;
#define rep(i,n) for(ll i=0;i<n;i++)
#define repl(i,l,r) for(ll i=(l);i<(r);i++)
#define per(i,n) for(ll i=n-1;i>=0;i--)
#define lper(i,r,l) for(ll i=r-1;i>=l;i--)
#define fi first
#define se second
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define CST(x) cout<<fixed<<setprecision(x)
using ll=long long;
using vl=vector<ll>;
using vvl=vector<vector<ll>>;
using pl=pair<ll,ll>;
const ll MOD=1000000007;
const ll MOD9=998244353;
const int inf=1e9;
const ll INF=4e18;
const ll dy[4]={1,0,-1,0};
const ll dx[4]={0,-1,0,1};
int main() {
ll A;
  ll B;
   ll C;
  ll X;
   ll Y;
  cin >>A>>B>>C>>X>>Y;
  
  ll c=2*C;
  ll n=max(X,Y);
  
  ll sum=0;
  rep(i,1000000) {
  if(i==0) {
  sum=A*X+B*Y;
}

else {
ll aa=C*2*i;
if((X-i>0) &&(Y-i>0)) {
aa+=(X-i)*A+(Y-i)*B;
}
else if((X-i>0) &&(Y-i<=0)){
aa+=(X-i)*A;


}
else if((X-i<=0) &&(Y-i>0)){
aa+=(Y-i)*B;
}
else if((X-i<=0) &&(Y-i<=0)){

}


sum=min(sum,aa);



}


}//endrep


cout<<sum<<endl;
}