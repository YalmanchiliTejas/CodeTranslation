#include <bits/stdc++.h>
using namespace std;
#define int long long
#define Rep(i, N) for(int i = 0; i < N; i++)
#define Reps(i, x, N) for(int i = x; i < N; i++)

const int LLINF = 1LL << 60;

string V = "yuiophjklnm";

bool check(char c) {
  Rep(i, V.size()) {
    if(c == V[i]) return true;
  }
  return false;
}

signed main()
{
  string S;
  while(cin >> S, S[0] != '#') {
    bool save = check(S[0]);
    int cnt = 0;

    Reps(i, 1, S.size()) {
      if(save != check(S[i])) {
	save = 1 - save, cnt++;
      }
    }
    cout << cnt << endl;
  }

  return 0;
}