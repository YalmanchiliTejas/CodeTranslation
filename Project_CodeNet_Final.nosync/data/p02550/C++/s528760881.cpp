#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;
using P = pair<ll, ll>;
string char_to_string(char val) {
  return string(1, val);
}
int char_to_int(char val) {
  return val - '0';
}
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
struct edge {
  ll to, cost;
};

int main() {
  ll N; cin >> N;
  ll X, M; cin >> X >> M;
  ll S = 0; // 最終的に答えとなる和
  vector<P> memo(M); // その値Xが { 何番目に出現したか, それまでの計算結果(和) }
  for(ll i = 0; i < N; ++i) {
    if(memo[X].first) { // もしその値がすでに配列にあれば、ループ最後の回りきらないフェーズまでワープさせる
      // 今の順番と、かつてXが出てきた番号の差。これが、ループ1周分の長さになる
      const auto t = i - memo[X].first;
      // この時点で、あとループを何周するか？
      const auto c = (N - i - 1) / t;
      // ループ1周分の長さ * ループを回る回数 をiに足し込む
      i += t * c;
      // ループ1周分の和(累積和っぽく求める) * ループを回る回数 をSに足し込む
      S += (S - memo[X].second) * c;
    } else { // もし配列にまだXが無ければ
      memo[X] = P(i, S); // 配列のX番目にpairを格納する。
    }
    // 必ずSとXを更新する
    S += X; (X *= X) %= M;
  }
  cout << S << endl;
}