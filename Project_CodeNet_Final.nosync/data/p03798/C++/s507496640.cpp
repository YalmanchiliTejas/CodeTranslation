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
  string s;
  cin >> s;

  vector<int> ox(N);
  for(int i = 0; i < N; i++){
    if(s[i] == 'o'){
      ox[i] = 0;
    }else{
      ox[i] = 1;
    }
  }

  bool ok = false;
  vector<int> ans(N);

  // 0, 1がS, S
  vector<int> test1(N);
  test1[0] = 0;
  test1[1] = 0;
  if(ox[0] == 0){
    test1[N-1] = 0;
  }else{
    test1[N-1] = 1;
  }

  for(int i = 2; i < N-1; i++){
    test1[i] = test1[i-1] ^ ox[i-1] ^ test1[i-2];
  }

  if(test1[N-1] == test1[N-2] ^ ox[N-2] ^ test1[N-3] &&
  test1[0] == test1[N-1] ^ ox[N-1] ^ test1[N-2]){
    ok = true;
    ans = test1;
  }

  // 0, 1がS, W;
  vector<int> test2(N);
  test2[0] = 0;
  test2[1] = 1;
  if(ox[0] == 0){
    test2[N-1] = 1;
  }else{
    test2[N-1] = 0;
  }

  for(int i = 2; i < N-1; i++){
    test2[i] = test2[i-1] ^ ox[i-1] ^ test2[i-2];
  }

  if(test2[N-1] == test2[N-2] ^ ox[N-2] ^ test2[N-3] &&
  test2[0] == test2[N-1] ^ ox[N-1] ^ test2[N-2]){
    ok = true;
    ans = test2;
  }

  // 0, 1がW, S;

  vector<int> test3(N);
  test3[0] = 1;
  test3[1] = 0;
  if(ox[0] == 0){
    test3[N-1] = 1;
  }else{
    test3[N-1] = 0;
  }

  for(int i = 2; i < N-1; i++){
    test3[i] = test3[i-1] ^ ox[i-1] ^ test3[i-2];
  }

  if(test3[N-1] == test3[N-2] ^ ox[N-2] ^ test3[N-3] &&
  test3[0] == test3[N-1] ^ ox[N-1] ^ test3[N-2]){
    ok = true;
    ans = test3;
  }
  // 0, 1がW, W;

  vector<int> test4(N);
  test4[0] = 1;
  test4[1] = 1;
  if(ox[0] == 0){
    test4[N-1] = 0;
  }else{
    test4[N-1] = 1;
  }

  for(int i = 2; i < N-1; i++){
    test4[i] = test4[i-1] ^ ox[i-1] ^ test4[i-2];
  }

  if(test4[N-1] == test4[N-2] ^ ox[N-2] ^ test4[N-3] &&
  test4[0] == test4[N-1] ^ ox[N-1] ^ test4[N-2]){
    ok = true;
    ans = test4;
  }

  if(ok){
    for(int i = 0; i < N; i++){
      if(ans[i] == 0){
        cout << 'S';
      }else{
        cout << 'W';
      }
    }
    cout << endl;
  }else{
    cout << -1 << endl;
  }


  return 0;
}
