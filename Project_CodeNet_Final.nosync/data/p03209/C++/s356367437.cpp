#include <bits/stdc++.h>
#define ll long long int
#define MOD 1000000007
#define INF 1e18

using namespace std;

vector<ll> size(51);

ll ans(ll n, ll x){
  if (n == 0)
    return 1;

  if (x == 1)
    return 0;


  if (x <= size[n-1] + 1)
    return ans(n - 1, x - 1);

  if (x == size[n-1] + 2)
    return ans(n - 1, size[n-1]) + 1;

  if (x < size[n])
    return ans(n-1, size[n-1]) + 1 + ans(n-1, x - size[n-1] - 2);

  return 2*ans(n-1, size[n-1]) + 1;
}

int main(void){
  size[0] = 1;
  for (int i = 0; i < 50; i++){
    size[i + 1] = 2*size[i] + 3;
  }
  
  ll n, x;
  cin >> n >> x;
  
  cout << ans(n, x) << endl;

  return 0;
}
