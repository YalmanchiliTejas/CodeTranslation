#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

void Main()
{
  int cnt[26] = {0};
  int n; cin >> n;
  rep(i,n) {
    string S;
  	cin >> S;
    int cntNow[26] = {0};
    for (char c : S) {
      cntNow[c - 'a']++;
    }
    if (i == 0) {
      rep(i,26) cnt[i] = cntNow[i];
    } else {
      rep(i,26) cnt[i] = min(cnt[i], cntNow[i]);
    }
  }
  rep(i,26) {
    rep(j, cnt[i]) cout << (char)('a' + i);
  }
  cout << "\n";
}

int main()
{
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  cout << fixed << setprecision(20);
  Main();
  return 0;
}
