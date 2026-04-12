#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>
#include <map>
#include <set>

using namespace std;

typedef long long i64;
typedef i64 int_t;
typedef vector<int_t> vi;
typedef vector<vi> vvi;

typedef pair<int_t, int_t> pi;

#define tr(c, i) for(auto i = (c).begin(); i != (c).end(); i++)
#define pb push_back
#define sz(a) int((a).size())
#define all(c) (c).begin(), (c).end()
#define REP(s, e, i) for(i=(s); i < (e); ++i)

int main(int argc, char *argv[]) {

  i64 N, S, i;
  cin >> N >> S;
  vi A(N);
  REP(0, N, i) {
    cin >> A[i];
  }

  i64 s;
  vi CL(S, 0); // sum value, starting point

  i64 NUM = 998244353LL;
  i64 ans = 0;
  REP(0, N, i) {
    if(A[i] == S) {
      ans += (i + 1) * (N - i);
      ans %= NUM;
    }
    else if(A[i] < S) {
      vi CL_new = CL;
      CL_new[A[i]] += i + 1;
      CL_new[A[i]] %= NUM;

      REP(0, S, s) {
	i64 s_new = s + A[i];
	if(s_new < S) {
	  CL_new[s_new] += CL[s];
	  CL_new[s_new] %= NUM;
	}
	else if(s_new == S) {
	  ans += CL[s] * (N - i);
	  ans %= NUM;
	}
      }
      CL.swap(CL_new);    
    }

    /*
    REP(0, S, s) {
      cout << CL[s] << " ";
    }
    cout << endl;
    */
  }

  cout << ans << endl;

  return 0;
}
