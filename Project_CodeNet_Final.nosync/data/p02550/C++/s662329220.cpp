#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef vector<int> VI;
ll mm=1000000000;ll MM=mm+7;
#define rep(i, n) for(int i=0;i<n;i++)
#define PI 3.141592653589793
 
   
int main(){
  ll n,x,m;
  cin >> n >> x >> m;
  unordered_set<ll> num;
  map<ll,int> pl;
  vector<ll> sum(10000000);
  ll ans=0;
  ans+=x;
  num.insert(x);
  ll a=x;
  sum.at(0)=x;
  pl[x]=0;

  ll b,c;
  bool d=false;
  rep(i,n-1){
      a=(a*a)%m;
      if(num.count(a)){
        b=i;
        c=a;
        d=true;
        break;
      }
      num.insert(a);
      pl[a]=i+1;
      ans+=a;
      sum.at(i+1)=ans;
  }
  if(d){
  ll lest=n-b-1;
  ll roop=b-pl.at(c)+1;
  ll rosum;
  if(pl.at(c)==0){
    rosum=sum.at(b);
  }
  else rosum=sum.at(b)-sum.at(pl.at(c)-1);
  ans+=(lest/roop)*rosum;
  ll ama=lest%roop;
  if(ama!=0){
    if(pl.at(c)==0) ans+=sum.at(pl.at(c)-1+ama);
    else ans+=sum.at(pl.at(c)-1+ama)-sum.at(pl.at(c)-1);
  }
  }
  cout << ans << endl;
} 
    