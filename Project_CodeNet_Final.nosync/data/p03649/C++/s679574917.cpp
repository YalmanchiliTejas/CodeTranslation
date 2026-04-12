#include <bits/stdc++.h>
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define FORR(i,a,b) for (int i=(a);i>=(b);i--)
#define pb push_back

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef set<int> si;
const int inf = 1e9;
const int mod = 1e9+7;

ll n, a[50];
main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> n;
  FOR(i, 0, n) cin >> a[i];
  ll count, ans=0;
  bool z=true;
  while (z){
    count = 0;
    z = false;
    FOR(i, 0, n){
      if(a[i] > n-1){
        z = true;
        count += a[i]/n;
      }
    }
    ans += count;
    FOR(i, 0, n){
      if(a[i] > n-1){
        a[i] += count-a[i]/n*(n+1);
      }else{
        a[i] += count;
      }
    }
  }
  cout << ans << endl;
}