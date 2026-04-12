#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll INF = 1LL<<60;

ll gcd(ll a, ll b) {
  if(b == 0) return a;
  return gcd(b, a % b);
}

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

ll modpow(ll a, ll n, ll mod) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    deque<ll> dq;

    ll tmp;
    for(int i = 0; i < N; i++){
      cin >> tmp;
      int ind = lower_bound(dq.begin(), dq.end(), tmp) - dq.begin();
      if(ind == 0){
        dq.push_front(tmp);
      }else{
        dq[ind-1] = tmp;
      }
    }

    cout << dq.size() << endl;


    return 0;
}

