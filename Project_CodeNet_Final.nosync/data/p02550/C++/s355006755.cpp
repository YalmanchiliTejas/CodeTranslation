#include <bits/stdc++.h>
//#include <atcoder/all>
#define ll long long int
#define MOD 1000000007
#define P pair<ll,ll>
#define INF 1000000000000000000

//using namespace atcoder;
using namespace std;

int main(void){
  ll n, x, m;
  cin >> n >> x >> m;
  
  vector<ll> store(0);
  set<ll> check;

  ll sum = 0;
  ll ans = 0;
  while (check.find(x) == check.end()){
    store.emplace_back(x);
    check.insert(x);
    sum = sum + x;

    x = x*x % m;
  }

  if (n <= store.size()){
    for (ll i = 0; i < n; i++){
      ans += store[i];
    }
  }
  else {
    ll id = 0;
    for (ll i = 0; i < store.size(); i++){
      if (store[i] == x){
        id = i;
        break;
      }
    }


    ans = sum;


    for (ll i = 0; i < id; i++){
      sum -= store[i];
    }

    ll l = store.size() - id;

    ans += sum * ((n - id) / l - 1);


    for (ll i = 0; i < (n - id) % l; i++){
      ans += store[id + i];
    }
  }

  cout << ans << endl;



  return 0;
}
