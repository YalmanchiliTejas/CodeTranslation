#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (ll i = 0; i < (n); i++)
typedef pair<ll,ll> P;

ll gcd(ll a, ll b) { return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) { return a/gcd(a,b)*b;}

int main(){
  ll n;
  cin >> n;

  deque<ll> list;
  ll top; cin >> top;
  list.push_back(top);

  rep(i,n-1){
    ll x;
    cin >> x;
    auto it = lower_bound(list.begin(), list.end(),x);
    ll d = distance(list.begin(), it);
    if(d==0){
      list.push_front(x);
    }else{
      list[d-1] = x;
    }

    // sort(list.begin(), list.end(), less<ll>());
  }
  cout << list.size() << endl;

  return 0;
} 
