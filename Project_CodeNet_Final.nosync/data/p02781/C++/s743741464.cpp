#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define REP2(i, x, n) for(int i = x; i < (int)(n); i++)
#define ALL(n) begin(n), end(n)
//struct cww{cww(){ios::sync_with_stdio(false);cin.tie(nullptr);}}star;
const long long INF = numeric_limits<long long>::max();

int count(char*, int);
int fact(int);
int combi(int, int);

int main() {
  char str[200];
  int k;
  scanf("%s", str);
  scanf("%d", &k);

  int length = strlen(str);

  printf("%d\n", count(str, k));

  return 0;
}

// 数値を表す文字列と残りのk（0以外の数）
int count(char* str, int k) {
  // 0以外の数値を入れられない場合、パターン数1
  if (k == 0) return 1;
  int length = strlen(str);
  if (length == 0) return 0;
  // 0以外の数値をk個含められない場合はパターン数0
  if (k > length) return 0;

  int total = 0;
  // 文字列が"n"(長さが1)なら1～nのnパターン kは1のはず
  if (length == 1 && k == 1) {
    return str[0] - '0';
  }

  // 最上位が0なら下位を調べる
  if (str[0] == '0') return count(&(str[1]), k);

  // 最上位桁をnに固定したパターン
  total += count(&(str[1]), k - 1);

  // 最上位桁を1～(n-1)に固定したパターン
  total += (str[0] - '0' - 1) * combi(length - 1, k - 1) * pow(9, k - 1);

  // 最上位桁を0に固定したパターン
  total += combi(length - 1, k) * pow(9, k);
  return total;
}

// 階乗
int fact(int n) {
  int sum = 1;
  for (int i = 1; i <= n; ++i) {
      sum *= i;
  }
  return sum;
}

// 組み合わせの数
int combi(int n, int r) {
  int p = 1;
  for (int i = n; i > n - r; --i) {
    p *= i;
  }
  return p / fact(r);
}
