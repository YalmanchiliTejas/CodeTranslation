#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MOD = pow(10, 9) + 7;
//const int MOD = 998244353;
//const int MOD = ;
int mod(int A, int M) {return (A % M + M) % M;}
const int INF = 1LL << 60;
template <class T> bool chmin(T& a, T b) {if (a > b) {a = b; return true;} return false;}
template <class T> bool chmax(T& a, T b) {if (a < b) {a = b; return true;} return false;}
int divCeil(int A, int B) {return (A + (B - 1)) / B;}
int myctoi(char C) {return C - 48;}
char myitoc(int N) {return '0' + N;}

signed main()
{
  int N, M;
  cin >> N >> M;

  vector<vector<bool> > G(N, vector<bool>(N));
  for (int i = 0; i < M; i++)
  {
    int a, b;
    cin >> a >> b;
    a--; b--;
    G.at(a).at(b) = true;
    G.at(b).at(a) = true;
  }
  
  vector<int> p(N);
  for (int i = 0; i < N; i++)
  {
    p.at(i) = i;
  }
  
  int ans = 0;
  do
  {
    bool ok = true;
    for (int i = 0; i < N - 1; i++)
    {
      if (!G.at(p.at(i)).at(p.at(i + 1)))
      {
        ok = false;
        break;
      }
    }
    if (ok) ans++;
  } while (next_permutation(p.begin(), p.end()) && p.at(0) == 0);
  
  cout << ans << endl;
}