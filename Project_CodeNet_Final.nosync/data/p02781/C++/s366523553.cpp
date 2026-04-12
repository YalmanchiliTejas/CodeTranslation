#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define pa(x,n) for(ll i=0;i<n;i++){cout<<(x[i])<<" \n"[i==n-1];};
#define pb push_back

using ll = long long;
using namespace std;
using pint = pair<int,int>;
using pll = pair<ll,ll>;
const int INFint = 1e9;
const ll INFll = 1e18;
ll MOD=1e9+7;

ll gcd(ll a, ll b) { return __gcd(a,b); } //最大公約数
ll lcm(ll a, ll b) { return a/gcd(a,b)*b; } //最大公倍数

// aのn乗をMODで割りながら計算する
ll modpow(ll a, ll n) {
  long long res = 1;
  while (n > 0) {
    if (n & 1) res = res * a % MOD;
    a = a * a % MOD;
    n >>= 1; // right shift
  }
  return res;
}

// MODを法としたaの逆元を計算する
ll modinv(ll a) {
  return modpow(a, MOD - 2);
}
int k1(string s){
  int n = int(s.size());
  return (n-1)*9 + (s[0]-'0');
}
int k2(string s){
  int n = int(s.size());
  int cnt(1),ret(0);
  ret = (n-1)*(n-2)/2*9*9 + (n-1)*9*(s[0]-'0'-1);
  n--;
  while(cnt < int(s.size()) && s[cnt] == '0'){
    cnt++;
    n--;
  }
  if (n>=1){
    return ret + k1(s.substr(cnt,int(s.size())-cnt));
  }else{
    return ret;
  }
}
int k3(string s){
  int n = int(s.size());
  int cnt(1),ret(0);
  ret = (n-1)*(n-2)*(n-3)/6*9*9*9 + (n-1)*(n-2)/2*9*9*(s[0]-'0'-1);
  n--;
  while(cnt < int(s.size()) && s[cnt] == '0'){
    cnt++;
    n--;
  }
  if (n>=2){
    return ret + k2(s.substr(cnt,int(s.size())-cnt));
  }else{
    return ret;
  }
}

int main(){
  string s;
  int K;
  cin>>s>>K;
  int n = int(s.size());
  if (n < K){
    cout << 0 << endl;
    return 0;
  }else{
    if (K == 1) {
      cout << k1(s) << endl;
    }else if (K==2){
      //cout << (n-1)*9*(s[0]-'0'-1) +s[1]-'0' + (n-2)*9 + (n-1)*(n-2)/2*9*9 << endl;
      cout << k2(s) << endl;
    }else{
      //cout << (n-1)*(n-2)*(n-3)/6*9*9*9 + (s[0]-'0'-1)*(n-1)*(n-2)/2*9*9 + (n-2)*9*(s[1]-'0'-1) +s[2]-'0' + (n-3)*9 + (n-2)*(n-3)/2*9*9 << endl;
      //int tmp = (n-1)*(n-2)*(n-3)/6*9*9*9 + (s[0]-'0'-1)*(n-1)*(n-2)/2*9*9;
      //int cnt(1);
      //n--;
      //while(s[cnt] == '0'){
      //  cnt++;
      //  n--;
      //}
      ////cout<< tmp << " " <<cnt<< " " << n <<endl;
      //if (n>=2){
      //  cout << tmp + (n-1)*9*(s[cnt]-'0'-1) +s[cnt]-'0' + (n-2)*9 + (n-1)*(n-2)/2*9*9 <<endl;
      //}else{
      //  cout << tmp << endl;
      //}
      cout << k3(s) << endl;
    }
  }
  return 0;
}

