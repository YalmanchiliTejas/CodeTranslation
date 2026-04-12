#include <bits/stdc++.h>

using namespace std;

typedef long long i64;
typedef i64 int_t;
typedef vector<int_t> vi;
typedef vector<vi> vvi;

typedef pair<int_t, int_t> pi;

#define tr(c, i) for(auto i = (c).begin(); i != (c).end(); i++)
#define pb push_back
#define sz(a) i64((a).size())
#define all(c) (c).begin(), (c).end()
#define REP(s, e, i) for(i=(s); i < (e); ++i)

int main(int argc, char *argv[]) {

  i64 N, X, M;
  cin >> N >> X >> M;

  unordered_map<i64, i64> Am;
  vi A;
  A.reserve(M * 2);  
  A.pb(X);
  Am[X] = 0;
  
  i64 next = (A.back() * A.back()) % M;

  while(Am.find(next) == Am.end()) {
    Am[next] = A.size();
    A.pb(next);
    next = (A.back() * A.back()) % M;
  }

  i64 loop_begin = Am[next];
  i64 loop_end = A.size();
  i64 loop_len = loop_end - loop_begin;

  i64 N1 = min(N, loop_begin);
  i64 N2 = N - N1;
  
  i64 LC = N2 / loop_len;
  i64 LL = N2 % loop_len;

  i64 S1 = accumulate(A.begin(), A.begin() + N1, 0LL);
  
  i64 S2 = accumulate(A.begin() + loop_begin, A.end(), 0LL);
  i64 S3 = accumulate(A.begin() + loop_begin, A.begin() + loop_begin + LL, 0LL);

  cout << S1 + S2 * LC + S3 << endl;

  return 0;
}
