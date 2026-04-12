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
  int n;
  cin >> n;
  vint A(n);
  rep(i,n) cin >> A[i];
  sort(A.begin(),A.end());
  int fans = 0,sans = 0;
  if(n % 2 == 0){
      rep(i,n/2-1){
        fans += A[n-1-i]*2;
        fans -= A[i]*2;
      }
      fans += A[n/2];
      fans -= A[n/2-1];
      cout << fans << endl;
  }
  else{
    rep(i,n/2-1){
        fans += A[n-1-i]*2;
        fans -= A[i]*2;
    }
    sans = fans;
    fans -= A[n/2-1];
    fans -= A[n/2];
    fans += A[n/2+1]*2;
    sans -= A[n/2-1]*2;
    sans += A[n/2];
    sans += A[n/2+1];
    cout << max(fans,sans) << endl;
  }
}