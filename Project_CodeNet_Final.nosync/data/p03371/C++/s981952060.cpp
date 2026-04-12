#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lvector vector<ll>
#define lque queue<ll>
#define lpque priority_queue<ll>
#define dlpque priority_queue<ll,lvector,greater<ll>>
#define P pair<ll,ll> 
#define ALL(a) (a).begin(),(a).end()
#define rep(i,n) for(ll (i)=0; (i)<(n); ++(i))
#define print(a) cout << (a) << endl

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll a,b,c,x,y;cin>>a>>b>>c>>x>>y;
  ll ans=a*x+b*y,ans_=ans,anum=x,bnum=y;
  while(!(anum==0&&bnum==0)) {
    ans_+=2*c;
    if(anum>0) {ans_-=a;anum--;}
    if(bnum>0) {ans_-=b;bnum--;}
    ans=min(ans,ans_);
  }
  print(ans);
  return 0;
}