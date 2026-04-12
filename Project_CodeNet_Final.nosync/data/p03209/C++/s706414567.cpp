#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define rep(i,n) for(int i=0; i<n; i++)
#define all(x) (x).begin(),(x).end()
#define INF (1e9)

ll a[60];
ll p(ll n,ll x){//レベルnでx層食べるときのパティの枚数
  if(n==0)return 1;
  if(x==1)return 0;
  if(x==a[n-1]+2)return p(n-1,a[n-1])+1;
  if(x==2*a[n-1]+3)return 2*p(n-1,a[n-1])+1;
  if(1<x && x<a[n-1]+2)return p(n-1,x-1);
  if(a[n-1]+2<x && x<2*a[n-1]+3)return p(n-1,a[n-1])+p(n-1,x-a[n-1]-2)+1;
}

int main(){
  ll n,x;
  a[0] = 1;
  for(int i=1; i<=50; i++){
    a[i] = 2*a[i-1]+3;
  }

  cin >> n >> x;
  cout << p(n,x) << endl;
}