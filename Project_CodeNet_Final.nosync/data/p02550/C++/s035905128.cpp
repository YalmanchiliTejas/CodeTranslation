#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
int gcd(int x, int y) { return (x % y)? gcd(y, x % y): y; }    //最大公約数
ll lcm(ll x, ll y) { return x / gcd(x, y) * y; }     //最小公倍数
using Graph = vector<vector<int>>;
ll inf=300000000000000000;
const double PI = 3.14159265358979323846;
int main(){
  ll n,x,m;
  cin >> n >> x >> m;
  ll ans=0;
  vector<ll> o(m);
  rep(i,m){
    ll h=i;
    o[i]=(h*h)%m;
  }
  rep(i,m)o[i]%=m;
  //rep(i,m)if(o[i]<=m)cout << i << endl;
  set<ll> s;
  while(true){
    n--;
    if(n==0){
      ans+=x;
      cout << ans << endl;
      return 0;
    }
    if(s.count(x))break;
    s.insert(x);
    ans+=x;
    //cout << x << endl;
    x=(o.at(x)%m);
  }
  int a=0;
  ll b=0;
  ll z=x;
  while(true){
    a++;
    b+=x;
    //if(o.at(x)>100000)cout << x << endl;
    x=o.at(x);
    if(x==z)break;
  }
  ans+=b*(n/a);
  n%=a;
  rep(i,n){
    ans+=x;
    //if(o.at(x)>100000)cout << x << endl;
    x=o.at(x);
  }
  ans+=x;
  cout << ans << endl;
}
