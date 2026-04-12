#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n - 1; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define FORR(i, m, n) for(int i = m; i >= n; i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define ll long long
#define pb(a) push_back(a)

ll mod = 1e09;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  char c;
  cin >> c;
  char p[5] = {'a', 'i', 'u', 'e', 'o'};
  int f = 0;
  REP(i, 5){
    if(c == p[i]) f = 1;
  }
  if(f) cout << "vowel";
  else cout << "consonant";
  return 0;
}
