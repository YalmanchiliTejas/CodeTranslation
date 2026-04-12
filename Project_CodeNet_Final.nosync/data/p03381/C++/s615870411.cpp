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
template<class T> void operator>> (istream& ist, vector<T>& vs) { for(auto& e: vs) cin >> e; }

typedef long long ll;
int const inf = 1<<29;

int main() {
  int N; cin >> N;
  vector<int> vs(N);
  rep(i, N) {
    cin >> vs[i];
  }
  auto copied = vs;
  sort(copied.begin(), copied.end());
  int m1 = copied[N / 2 - 1], m2 = copied[N / 2];
  rep(i, N) {
    if (vs[i] < m2) {
      cout << m2 << "\n";
    } else {
      cout << m1 << "\n";
    }
  }
}
