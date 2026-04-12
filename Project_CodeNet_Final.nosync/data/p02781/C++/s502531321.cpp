// ref. https://drken1215.hatenablog.com/entry/2020/02/09/225300
#include <iostream>
#include <string>

template <typename T>
T nCk(int n, int k) {
  if (k > n) return 0;
  T ret = 1;
  for (auto i = 0; i < std::min(n - k, k); ++i) {
    ret *= n - i;
    ret /= i + 1;
  }
  return ret;
}

template <typename T>
T power(T x, int n) {
  T ans{1};
  while (n) {
    if (n % 2) ans *= x;
    x *= x;
    n >>= 1;
  }
  return ans;
}

using namespace std;
using ll = long long;

string S;
int N, K;


// i: 確定済みの桁数
// k: 残り使用可能な0以外の桁の数
// smaller: i桁目までを見たとき、Nよりも小さいかどうか
ll solve(int i, int k, bool smaller) {
  if (!k)
    return 1;  // 0以外の数が入る桁を使い果たしているので、以降の桁は全て0になるしか無い。
  if (i == N) {  // N桁目まですべて数が確定している
    // ここに来ているということは0以外の桁がまだ余っているので、条件を満たせない
    return 0;
  }

  if (smaller) { // i桁目までで、既にNより小さいことが確定している。
    // これ以降の桁は0...0から9...9の間の数のうち、
    // k個の桁が0でない数であれば良い。
    return nCk<ll>(N - i, k) * power<ll>(9, k);
  }

  // この桁が0の場合、選択肢はないので次の桁に移る。
  if(S[i] == '0') return solve(i+1,k,false);

  // ここまでたどり着いた場合、この桁に0以外の数が入りうるので、場合分けをする。
  // zero: 0を入れる場合、smallerはtrueになる。
  ll zero = solve(i+1,k,true);
  // icchi: 最大値を入れる場合、smallerはfalseのまま。kは一つ減る。
  ll icchi = solve(i+1,k-1,false);
  // others: その他の場合、kは一つ減り、smallerはtrueになる。
  ll others = solve(i+1,k-1,true) * (S[i] - '1');

  return zero + icchi + others;
}

int main() {
  cin >> S >> K;
  N = S.size();
  cout << solve(0, K, false) << endl;
  return 0;
}
