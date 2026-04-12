#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll MOD = 1000000007;

template<typename T>
void remove(std::vector<T>& vector, unsigned int index)
{
    vector.erase(vector.begin() + index);
}


ll modpow(ll a,ll n,ll m){//modpow(a,n,m) := a ^ n (mod m)
  ll res = 1;
  while(n > 0){
    if(n & 1)res = res * a % m;
    a = a * a % m;
    n >>= 1;
  }
  return res;
}

ll modinv(ll a,ll p){//modinv(a,p) := pを法とするaの逆元(※pは素数でなければならない)
    ll res = modpow(a,p-2,p);
    return res;
}

int main(){
  int N;cin >> N;
  vector<string> S(N);
  int cnt[26];
  for(int i = 0;i < 26;i++){
    cnt[i] = 1000000;
  }
  for(int i = 0;i < N;i++){
    cin >> S[i];
  }
  for(int i = 0;i < N;i++){
    for(int j = 0;j < 26;j++){
      char q = 'a' + j;
      int a = count(S[i].begin(),S[i].end(),q);
      cnt[j] = min(a,cnt[j]);
    }
  }
  string ans = "";
  for(int i = 0;i < 26;i++){
    char p = 'a' + i;
    for(int j = 0;j < cnt[i];j++){
      ans = ans + p;
    }
  }
  cout << ans << endl;
}