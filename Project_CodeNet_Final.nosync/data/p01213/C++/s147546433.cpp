#include <bits/stdc++.h>

using namespace std;

#define REP(i,a,b) for(int i=a;i<(int)b;i++)
#define rep(i,n) REP(i,0,n)
#define all(c) (c).begin(), (c).end()
#define zero(a) memset(a, 0, sizeof a)
#define minus(a) memset(a, -1, sizeof a)
#define watch(a) { cout << #a << " = " << a << endl; }
template<class T1, class T2> inline bool minimize(T1 &a, T2 b) { return b < a && (a = b, 1); }
template<class T1, class T2> inline bool maximize(T1 &a, T2 b) { return a < b && (a = b, 1); }

typedef long long ll;
int const inf = 1<<29;

const int Max = 303;

int main() {

  for(string s_; cin >> s_ && s_ != "#END";) {
    const int N = s_.size();

    string max_string;
    int max_length = 0;

    REP(k, 1, N) {
      const int sn = k;
      const int tn = N - k;
      string s = string(s_.begin(), s_.begin() + sn);
      string t = string(s_.begin() + sn, s_.end());
      int dp[Max][Max];
      int trans[Max][Max];

      zero(dp);
      minus(trans);

      rep(i, sn) {
        rep(j, tn) {
          if(s[i] == t[j]) {
            dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + 1);
            trans[i + 1][j + 1] = 2;
          }
          else if(dp[i + 1][j] > dp[i][j + 1]) {
            dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i + 1][j]);
            trans[i + 1][j + 1] = 0;
          }
          else {
            dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j + 1]);
            trans[i + 1][j + 1] = 1;
          }
        }
      }

      if(dp[sn][tn] > 0) {
        int i = sn, j = tn;
        string res;
        while(trans[i][j] >= 0) {
          if(trans[i][j] == 1) i--;
          else if(trans[i][j] == 0) j--;
          else {
            i--, j--;
            res.push_back(s[i]);
          }
        }

        if(max_length < res.size()) {
          reverse(res.begin(), res.end());
          max_length = res.size();
          max_string = res;
        }
      }
    }

    cout << max_string << endl;
  }
  
  return 0;
}