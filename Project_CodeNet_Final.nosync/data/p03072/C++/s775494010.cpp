#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repr(i, n) for (int i = (int)(n); i >= 0; i--)
#define REP(i, m, n) for (int i = (int)(m); i < (int)(n); i++)
#define INF 1e9
#define all(v) v.begin(), v.end()
typedef long long ll;

int main(){
  int n;
  cin >> n;

  int max = 0;
  int cnt = 0;
  rep(i, n){
    int h;
    cin >> h;
    if(h >= max){
      max = h;
      cnt++;
    }
  }

  cout << cnt << endl;

  return 0;
}
