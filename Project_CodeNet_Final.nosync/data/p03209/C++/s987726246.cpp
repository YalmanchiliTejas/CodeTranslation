#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,N) for(ll (i)=0;(i)<(N);(i)++)
const int mod = 1000000007;

vector<ll> b(110), a(110);

ll dfs(ll n, ll x){
  if(n == 0){
    if(x <= 0) return 0;
    else return 1;
  } else if(x > a[n - 1] + 1) {
    return b[n - 1] + 1 + dfs(n - 1, x - a[n - 1] - 2);
  } else {
    return dfs(n - 1, x - 1);
  }
}

int main(){
  ll n, x;
  cin >> n >> x;
  b[0] = 1; a[0] = 1;
  for(int i = 1; i <= n; ++i){
    b[i] = (2 * b[i - 1]) + 1;
    a[i] = (2 * a[i - 1]) + 3;
  }
  cout << dfs(n, x) << endl;
}