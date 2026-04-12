#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
using ll = long long;
#define vl vector<long long>
#define vvl vector<vector<long long>>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using pll = pair<long long,long long>;
#define cY cout<<"Yes"<<endl
#define cN cout<<"No"<<endl
const long long INF = 1LL << 60;
const long long MOD = 1000000007;

//最大最小の入れ替え
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

//約数列挙
vector<long long> divisor(long long n) {
    vector<long long> ret;
    for (long long i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ret.push_back(i);
            if (i * i != n) ret.push_back(n / i);
        }
    }
    sort(ret.begin(), ret.end()); // 昇順に並べる
    return ret;
}
//コンビネーション
ll nCr(ll n, ll r) {
    ll ans = 1;
    for (int i = n; i > n - r; --i) {
        ans = ans*i;
    }
    for (int i = 1 ; i < r + 1; ++i) {
        ans = ans / i;
    }
    return ans;
}
//素因数分解
map< ll, ll > prime_factor(ll n) {
  map< ll, ll > ret;
  for(ll i = 2; i * i <= n; i++) {
    while(n % i == 0) {
      ret[i]++;
      n /= i;
    }
  }
  if(n != 1) ret[n] = 1;
  return ret;
}

//切り上げの割り算は(a + b - 1) / bでできる
//時間を意識しろ
//コードテストちゃんとして
//画面とにらめっこするな書け
//WA出すたびにABCは五億円払え
//わからない問題はとばせ
//躊躇なくぐぐれ

//ここから
int main(){
    ll H,W;
    cin>>H>>W;
    vector<bool> h(H,false);
    vector<bool> w(W,false);
    vector<vector<char>> grid(W,vector<char>(H));
    rep(i,H){
        rep(j,W){
            cin>>grid.at(j).at(i);
        }
    }
    rep(i,W){
        rep(j,H){
            if(grid.at(i).at(j)=='#'){
                h.at(j)=true;
                w.at(i)=true;
            }
        }
    }
    rep(i,H){
        bool check=false;
        rep(j,W){
            if(w.at(j)&&h.at(i)){
                cout<<grid.at(j).at(i);
                check=true;
            }
            if(j==W-1&&check){
                cout<<endl;
            }
            }
        }
    }

