#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll mod = 10e9+7;

#define vec vector<int>
#define vecll vector<ll>
#define vpair vector<pair<int, int>>
#define vpairll vector<pair<ll, ll>>

#define rep(i,n)   for(int i=(int)0; i<(int)n; i++)
#define REP(i,m,n) for(int i=(int)m; i<(int)n; i++)
#define all(var)     (var).begin(), (var).end()
#define prt(var)     cout << var << endl
#define prtd(n, var)  cout << fixed << setprecision(n) << var << endl
#define prt2(var1, var2) cout << var1 << " " << var2 << endl

//----------------------------------------------------------------

int main(void) {
  int n;
  cin >> n;

  vec h(n);
  rep(i,n){
    cin >> h[i];
  }

  int ans=0;
  int temp=0;

  rep(i,n){
    if(temp<=h[i]){
      ans++;
      temp = h[i];
    }
  }

  prt(ans);
}
