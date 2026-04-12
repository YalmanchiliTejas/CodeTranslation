#include <iostream>
#include <algorithm>
#include <vector>

#define REP(i,n) for(int i = 0; i < (int)(n); i++)

using namespace std;

typedef long long ll;

inline int getInt(){ int s; scanf("%d\n", &s); return s; }

bool check(const vector<ll> &a, ll v, ll th){
  const int n = a.size();
  ll cnt = 0;

  for(const ll aa : a){
    // aa - n * k + (v - k) <= th
    // aa - th + v <= (n + 1)k
    // k >= (aa - th + v + n) / (n + 1)
    const ll k = (aa - th + v + n) / (n + 1);
    cnt += k;
  }

  // printf("%lld: %lld\n", v, cnt);
  return cnt <= v;
}

vector<ll> emulate(const vector<ll> &a, ll v, ll th){
  const int n = a.size();
  vector<ll> ret(n);
  for(int i = 0; i < n; i++){
    const ll aa = a[i];
    const ll k = (aa - th + v + n) / (n + 1);
    ret[i] = aa - k * n + (v - k);
  }
  return ret;
}

int main(){
  int n; cin >> n;
  vector<ll> a(n); REP(i,n) cin >> a[i];

  ll high = 1ll << 60;
  ll low = 0;
  while(low <= high){
    const ll mid = (high + low) / 2;
    if(check(a, mid, 2 * n)) high = mid - 1;
    else low = mid + 1;
  }

  ll cnt = low;
  a = emulate(a, cnt, 2 * n);

  while(true){
    auto it = max_element(a.begin(), a.end());
    if(*it < n) break;

    *it -= n + 1;
    for(auto &aa : a) aa += 1;
    cnt++;
  }

  cout << cnt << endl;

  return 0;
}