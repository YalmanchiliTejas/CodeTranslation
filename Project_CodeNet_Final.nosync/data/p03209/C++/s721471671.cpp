#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> P;

#define rep(i, n) for (ll i = 0; i < (int)(n); i++)
const int INF = 1001001001;
const ll mod = 1e9+7;

vector<ll>v(50);
vector<ll>a(50);

ll d(ll i,ll x){
//  cout<<i<<'i'<<x<<'x'<<endl;
  if (x<=0)return 0;
  if (i==0)return 1;
  if (x<=v[i-1]+1)return (d(i-1,x-1));
  if (x==v[i-1]+2)return (a[i-1]+1);
  if (x>v[i-1]+2)return (a[i-1]+1+d(i-1,x-v[i-1]-2));
}

int main() {
  ll n,x;
  cin>>n>>x;


  v[0]=1;
  a[0]=1;
  rep(i,n-1){
    v[i+1]=v[i]*2+3;
    a[i+1]=a[i]*2+1;
  }
cout<<d(n,x);


}
