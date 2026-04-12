#include <bits/stdc++.h>
using namespace std;

#define df(b, e) ((b) > (e))
#define fore(i, b, e) for(auto i = (b) - df(b, e); i != e - df(b, e); i += 1 - 2 * df(b, e))
#define sz(x) (int) x.size()
#define all(x) x.begin(), x.end()
#define f first
#define s second
#define pb push_back

typedef long long lli;
typedef long double ld;
typedef pair<int, int> ii;

const int N = 101;
const int K = 4;

lli mem[N][K][2];
short done[N][K][2], timer = 0;
string num;
int k;

lli dp(int i, int cnt, bool small) {
  if (cnt > k)  
    return 0LL;
  if (i == sz(num))
    return cnt == k;
  lli &ans = mem[i][cnt][small];
  if (done[i][cnt][small] != timer) {
    done[i][cnt][small] = timer;
    ans = 0;
    int lo = 0, hi = small ? 9: num[i] - '0';
    fore (x, lo, hi + 1) 
      ans += dp(i + 1, cnt + (x != 0), small | (x < hi));
  } 
  return ans;
} 

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  while (cin >> num >> k) {
    ++timer;
    cout << dp(0, 0, 0) << '\n';
  }
  return 0;
}
