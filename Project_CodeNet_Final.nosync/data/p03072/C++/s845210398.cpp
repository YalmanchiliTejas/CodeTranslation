#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define reps(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)   reps(i,0,n)
#define all(x) (x).begin(),(x).end()
#define INF (1000000000)
#define MOD (1000000007)
#define PI (acos(-1))

int main(){
  int n;
  cin >> n;
  int h[n];
  rep(i,n){
    cin >> h[i];
  }

  int cnt = 0;
  rep(i,n){
    bool ok = 1;
    rep(j,i){
      if(h[j] > h[i]){
        ok = 0;
        break;
      }
    }
    if(ok)cnt++;
  }

  cout << cnt << endl;
}