#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,val) for(int i = 0; i < val; i++)

const long long INF = 1LL << 60;
const ll MOD = ll(1e9)+7;

bool has_key(unordered_map<string, ll> &m, string s){
    if (m.find(s) == m.end()){
        return false;
    }
    else{
        return true;
    }
}


bool vector_find(std::vector<ll> vec, ll number) {
  auto itr = std::find(vec.begin(), vec.end(), number);
  size_t index = std::distance( vec.begin(), itr );
  if (index != vec.size()) {
    return true;
  }
  else {
    return false;
  }
}


void recursive_comb(int *indexes, int s, int rest, std::function<void(int *)> f) {
  if (rest == 0) {
    f(indexes);
  } else {
    if (s < 0) return;
    recursive_comb(indexes, s - 1, rest, f);
    indexes[rest - 1] = s;
    recursive_comb(indexes, s - 1, rest - 1, f);
  }
}


void foreach_comb(int n, int k, std::function<void(int *)> f) {
  int indexes[k];
  recursive_comb(indexes, n - 1, k, f);
}

bool compare_by_b(pair<ll, ll> a, pair<ll, ll> b) {
    if(a.second != b.second){
        return a.second < b.second;
    }else{
        return a.first < b.first;
    }
}

ll count_black(vector<vector<string>> C) {

  ll num = 0;
  for (ll i = 0; i < C.size(); i++) {
    for (ll j = 0; j < C.at(i).size(); j++) {
      if (C.at(i).at(j) == "#") num++;
    }
    
  }

  return num;
  
}

vector<vector<string>> paint(vector<vector<string>> C, vector<ll> x, vector<ll> y) {

  vector<vector<string>> C_painted = C;

  for (ll i = 0; i < x.size(); i++) {
    if(x.at(i) == 1) {
      for (ll j = 0; j < C_painted.size(); j++) {
        C_painted.at(j).at(i) = "r";
      }
    }
  }

  for (ll i = 0; i < y.size(); i++) {
    if(y.at(i) == 1) {
      for (ll j = 0; j < C_painted.at(0).size(); j++) {
        C_painted.at(i).at(j) = "r";
      }
    }
  }

  return C_painted;
  
}

vector<vector<ll>> vec_x;

void sublistx(vector<ll> tmp, ll n) {
    if (n == 0) {
      vec_x.push_back(tmp);
    }
    if (n > 0) {
      vector<ll> tmp0 = tmp;
      vector<ll> tmp1 = tmp;
      tmp0.push_back(0);
      tmp1.push_back(1);
      sublistx(tmp0, n - 1);
      sublistx(tmp1, n - 1);
    }
}

vector<vector<ll>> vec_y;

void sublisty(vector<ll> tmp, ll n) {
    if (n == 0) {
      vec_y.push_back(tmp);
    }
    if (n > 0) {
      vector<ll> tmp0 = tmp;
      vector<ll> tmp1 = tmp;
      tmp0.push_back(0);
      tmp1.push_back(1);
      sublisty(tmp0, n - 1);
      sublisty(tmp1, n - 1);
    }
}

ll modinv(ll a, ll m) {
    ll b = m, u = 1, v = 0;
    while (b) {
        ll t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}


int main() {

  ll N;
  cin >> N;

  vector<ll> A(N);

  ll sum = 0;
  ll sqsum = 0;

  for (ll i = 0; i < N; i++) {
    cin >> A.at(i);


    sum = (sum + A.at(i) % MOD) % MOD;
    sqsum = (sqsum + A.at(i) * A.at(i) % MOD) % MOD;
  }
  
  ll ans = ((sum*sum % MOD - sqsum)* modinv(2, MOD)) % MOD;

  if (ans < 0) ans = ans + MOD;


  cout << ans << endl;

  return 0;
}