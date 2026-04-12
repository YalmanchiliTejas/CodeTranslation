#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define m0(x) memset(x,0,sizeof(x))
const ll INF = 1001001001;
const ll MOD = 1e9 + 7;

ll a[51], p[51];
ll func(ll n,ll x){
  if(n == 0) return x <= 0 ? 0 : 1;
  if(x <= a[n-1] + 1) return func(n-1, x-1);
  return p[n-1] + 1 + func(n-1, x - 2 - a[n-1]);
}

int main(){
  ll n, x;
  cin >> n >> x;
  a[0] = 1; p[0] = 1;
  rep(i, 50){
    a[i+1]= 2*a[i] + 3; p[i+1] = 2*p[i]+1;
  }
  cout << func(n, x) <<endl;
}
  
  