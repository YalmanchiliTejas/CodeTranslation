#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define rep(i,s,e) for(i64 (i) = (s);(i) < (e);(i)++)
#define rev(i,s,e) for(i64 (i) = (e);(i) --> (s);)
#define all(x) x.begin(),x.end()

int main() {
  i64 N;
  cin >> N;
  vector<i64> s(N);
  rep(i,0,N) cin >> s[i];

  i64 ans = s[0] + s[N - 1];

  rep(C,1,N) {
    if((N - 1) % C == 0) {
      i64 now = 0;
      i64 i = 0;
      i64 j = N - 1;
      while(i < j) {
        now += s[i] + s[j];
        i += C;
        j -= C;
        ans = max(ans, now);
      }
    }
    else {
      i64 now = 0 ;
      i64 i = 0;
      i64 j = N - 1;
      while(i < N - 1 && C < j) {
        now += s[i] + s[j];
        i += C;
        j -= C;
        ans = max(ans, now);
      }
    }
  }
  cout << ans << endl;
}
