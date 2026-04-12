#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <cstring>
#define rep(i, N) for (int i = 0; i < (int)N; i++)
using namespace std;
typedef long long ll;
const ll LLINF = 9223372036854775807;
const int MOD = 1000000007;



int main() {
  int N; cin >> N;
  string s_tmp; cin >> s_tmp;
  bool s[N]; rep(i, N) s[i] = (s_tmp[i]=='o');

  bool a[N+2];
  string result = "";
  a[0] = true; a[1] = true;
  for(int i=1; i<=N; i++) a[i+1] = ( s[i-1] == (a[i]==a[i-1]) );
  if (a[0]==a[N]&&a[1]==a[N+1]) {
    result = "";
    for(int i=1; i<=N; i++) result+= (a[i] ? "S" : "W");
    cout << result << endl;
    return 0;
  }

  a[0] = true; a[1] = false;
  for(int i=1; i<=N; i++) a[i+1] = ( s[i-1] == (a[i]==a[i-1]) );
  if (a[0]==a[N]&&a[1]==a[N+1]) {
    result = "";
    for(int i=1; i<=N; i++) result+= (a[i] ? "S" : "W");
    cout << result << endl;
    return 0;
  }

  a[0] = false; a[1] = true;
  for(int i=1; i<=N; i++) a[i+1] = ( s[i-1] == (a[i]==a[i-1]) );
  if (a[0]==a[N]&&a[1]==a[N+1]) {
    result = "";
    for(int i=1; i<=N; i++) result+= (a[i] ? "S" : "W");
    cout << result << endl;
    return 0;
  }

  a[0] = false; a[1] = false;
  for(int i=1; i<=N; i++) a[i+1] = ( s[i-1] == (a[i]==a[i-1]) );
  if (a[0]==a[N]&&a[1]==a[N+1]) {
    result = "";
    for(int i=1; i<=N; i++) result+= (a[i] ? "S" : "W");
    cout << result << endl;
    return 0;
  }

  cout << -1 << endl;
  return 0;
}