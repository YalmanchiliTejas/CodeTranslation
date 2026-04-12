#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef vector<int> VI;
 
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)
#define all(x) (x).begin(),(x).end()

ll a[60],p[60];
ll finder(ll x,ll n){
  if(x==0)return 0;
  if(n==0)return 1;
  if(x==1)return 0;
  if(x==a[n])return p[n];
  if(x<=a[n]/2)return finder(x-1,n-1);
  if(x==a[n]/2+1)return p[n]/2+1;
  else return p[n]/2+1+finder(x-a[n-1]-2,n-1);
}

int main(){
  ll n,x;cin>>n>>x;
  a[0]=1;p[0]=1;
  rep(i,60-1){
    a[i+1]=a[i]+4ll*(1ll<<i);
    p[i+1]=p[i]+(1ll<<(i+1));
  }
  cout<<finder(x,n)<<endl;
}
