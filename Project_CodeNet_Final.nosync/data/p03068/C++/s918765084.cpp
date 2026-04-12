/*
    問題をよく読もう！
    論理的に考えよう！
    サンプルを確認しよう!
    絶対に諦めるな！
    工夫をしろ！
    配列は少し多めにとっておく

    Twitterは終わるまでログアウト！
    （間違えて解法をツイートしてはいけないから）

*/
//include
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<functional>
#include<assert.h>
#include<numeric>
#include<stdio.h>
#include<cstring>
//namespace
using namespace std;
//繰り返し
#define REP(i, m, n) for(int i=(int)m; i<(int)n; ++i)
#define rep(i, n) REP(i, 0, n)
//イテレータ
#define all_range(C) begin(C), end(C)
//簡略化
typedef long long ll;
typedef pair<int,int> pint;
typedef pair<ll,int> pli;
typedef pair<string,int> pst;

const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;
//最大最小
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b) {if(a>b) a=b;}
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b) {if(a<b) a=b;}

//関数

//最大公約数を求める
ll my_gcd(ll x, ll y) {
  ll r;

  while(y!=0) {
    r = x%y;
    x = y;
    y = r;
  }

  return x;
}

//最小公約数を求める
ll my_lcm(ll x, ll y) {

  return (x*y)/my_gcd(x,y);
}

//xのy乗を求める ※参考：10^18乗まで
ll my_pow(ll x, ll y) {
  ll sum = 1;

  while(y>0) {
    sum *= x;
    --y;
  }

  return sum;
}

/*考えを書くスペース


*/

//main.cpp----------------------------
bool dfs(int x, int y);

#define MAX 1000

ll n, k;
string s;

int main() {
  cin >> n >> s >> k;

  char c = s[k-1];

  rep(i, n) {
    if(s[i]!=c) cout << '*';
    else cout << s[i];
  }
  cout << endl;

  return 0;
}
