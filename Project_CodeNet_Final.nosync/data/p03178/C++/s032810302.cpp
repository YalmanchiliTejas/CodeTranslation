//In The Name Of God
#include <bits/stdc++.h>
#define int long long
#define F first
#define S second
#define mp make_pair
#define L(x) (2*(x))
#define R(x) ((2*(x))+1)
#define pii pair<int, int>
#define pb push_back
using namespace std;
const int N = 1e4 + 5, Mod = 1e9 + 7, P = 727, Lg = 22, TOF = 1900;

int A[N][105], B[N][105], Pw[N];

int32_t main(){
      ios_base::sync_with_stdio(0); cin.tie(0);
      string s; cin >> s;
      int d; cin >> d;
      int n = s.size(), Ans = 0;
      for(int i = 1; i < 10; i++)
            A[1][i % d]++, B[1][i % d]++;
      B[1][0]++, B[0][0] = 1;
      for(int i = 2; i <= n; i++){
            for(int j = 0; j < 10; j++){
                  for(int x = 0; x < d; x++){
                        int rem = j % d, nd = (x - rem + d) % d;
                        A[i][x] = (A[i][x] + A[i - 1][nd]) % Mod;
                        B[i][x] = (B[i][x] + B[i - 1][nd]) % Mod;
                  }
            }
      }
      for(int i = 1; i < n; i++)
            Ans = (Ans + A[i][0]) % Mod;
      for(int i = 1; i < (s[0] - '0'); i++)
            Ans = (Ans + B[n - 1][(d - i % d) % d]) % Mod;
      int now = 0;
      for(int i = 0; i < n - 1; i++){
            now = (now + (s[i] - '0')) % d;
            for(int j = 0; j < (s[i + 1] - '0'); j++){
                  int cur = (now + j % d) % d;
                  int nd = (d - cur) % d;
                  Ans = (Ans + B[n - i - 2][nd]) % Mod;
            }
      }
      now = (now + (s[n - 1] - '0')) % d;
      if(!now)
            Ans = (Ans + 1) % Mod;
      cout << Ans;
      return 0;
}

