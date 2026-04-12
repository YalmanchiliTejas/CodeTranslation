#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0;i<n;i++)
#define erep(i,n) for(int i = 0;i<=n;i++)
#define rep1(i,n) for(int i = 1;i<n;i++)
#define erep1(i,n) for(int i = 1;i<=n;i++)
typedef long long ll;
#define vint vector<int>
#define vvint vector<vector<int>>
#define vstring vector<string>
#define vdouble vector<double>
#define vll vector<ll>:
#define vbool vector<bool>
#define INF 1101010101010101010
#define MOD 1000000007
#define int long long
using P = pair<int,int>;

signed main(){
  int n,k;
  cin >> n >> k;
  int ans = 0;
  for(int i = k+1;i <= n;i++){
    int syou = n/i;
    int amari = n%i;
    if((i-1) >= k) ans += ((i-1) - k+1)*syou;
    if(amari >= k) ans += amari - k+1;
  }
  if(k != 0) cout << ans << endl;
  else{
    ans = pow(n,2);
    cout << ans << endl;
  }
}