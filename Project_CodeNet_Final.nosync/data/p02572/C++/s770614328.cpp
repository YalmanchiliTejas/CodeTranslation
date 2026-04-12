#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep1(i, n) for(int i = 1; i < n+1; i++)
#define all(A) A.begin(),A.end()
typedef long long ll;

const ll MOD = 1000000007;

int main(){
  int n;
  cin >> n;
  ll ans = 0;
  ll sum = 0;
  rep(i,n){
    int a;
    cin >> a;
    ans = (ans + sum*a)%MOD;
    sum = (sum + a)%MOD;
  }
  cout << ans << endl;
}
