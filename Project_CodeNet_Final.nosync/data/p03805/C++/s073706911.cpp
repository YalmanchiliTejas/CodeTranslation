#include <bits/stdc++.h>  // ver1.8
#define int long long
#define ALL(v) (v).begin(),(v).end()
#define Vi vector<int>
#define pb push_back
#define mp make_pair
#define rep(i,a,b) for(int i=a;i<b;i++)
#define repeq(i,a,b) for(int i=a;i<=b;i++)
#define repr(i,a,b) for(int i=a;i>b;i--)
#define repreq(i,a,b) for(int i=a;i>=b;i--)
#define leng(n) (int)(log10(n)+1)
#define INF 9000000000000000000  //  9.0 * 10^18
#define MOD 1000000007  //  10^9 + 7
#define PAI 3.14159265358979
using namespace std;

int gcd(int a,int b){return b?gcd(b,a%b):a;}  //  最大公約数gcd
int lcm(int a,int b){return a/gcd(a,b)*b;}  //  最小公倍数lcm

signed main() {
  cout << fixed << setprecision(14);
  int n,m;
  cin >> n >> m;
  Vi a(0);
  rep(i,0,n) a.pb(i+1);
  vector<pair<int,int>> line(m);
  int qw,er;
  rep(i,0,m){
    cin >> qw >> er;
    line[i] = mp(qw,er);
  }
  int ans = 0;
  bool ok1 = false;
  bool ok2 = false;
  do {
    if(a[0]!=1) break;
    ok2=false;
    
    rep(i,0,n-1){
      ok1=false;
      rep(j,0,m){
        if(mp(a[i],a[i+1])==line[j]) ok1 = true;
        if(mp(a[i+1],a[i])==line[j]) ok1 = true;
      }
      if(!ok1) break;
      if(i==n-2) ok2=true;
    }
    
    if(ok2) ans++;
  } while (next_permutation(ALL(a)));
  
  cout << ans << endl;
  
  return 0;
}
