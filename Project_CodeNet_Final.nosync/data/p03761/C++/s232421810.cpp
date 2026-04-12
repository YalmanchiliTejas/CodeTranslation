#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0, i##_len = (n); i < i##_len; ++i)
#define all(x) (x).begin(), (x).end()
#define clr(ar, val) memset(ar, val, sizeof(ar))
#define sbp(p, n) rep(i, n) { int a, b; scanf("%d %d", &a, &b); p[i] = make_pair(a, b); }
template <class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return 1; } return 0; }
template <class T> bool chmin(T &a, const T &b) { if (b < a) { a = b; return 1; } return 0; }
int gcd(int a,int b){return b?gcd(b,a%b):a;}
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair <int,int> P;
typedef long double ld;

int main(void)
{
  int s[26][50] = {}, x[26] = {}, n;
  clr(x, 50);
  cin >> n;
  rep(i, n){
    char str[51];
    cin >> str;
    rep(j, (int)strlen(str)) s[(int)str[j] - 'a'][i]++;
    rep(j, 26) chmin(x[j], s[j][i]);
  }
  rep(i, 26){
    rep(j, x[i]){
      cout << (char)(i + 'a');
    }
  }
  cout << endl;
  return 0;
}