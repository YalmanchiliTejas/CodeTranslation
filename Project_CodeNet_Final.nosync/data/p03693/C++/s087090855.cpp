#include <bits/stdc++.h>
#define repd(i,a,b) for (int i=(a);i<(b);i++)
#define rep(i,n) repd(i,0,n)
typedef long long ll;
const int MOD = 1000000007;
const int INF = 1010000000;
const double EPS = 1e-10;
using namespace std;
//cout << fixed << setprecision(0)
int main() { 
  int r,g,b;cin >> r >> g >> b;
  if((r*100+g*10+b)%4==0){
    cout << "YES" << endl;
  }else{
    cout << "NO" << endl;
  }
}
