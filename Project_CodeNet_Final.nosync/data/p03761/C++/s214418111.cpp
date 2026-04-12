#include <bits/stdc++.h>
#define int long long
#define ALL(v) (v).begin(),(v).end()
#define Vi vector<int>
#define pb push_back
#define rep(i,a,b) for(int i=a;i<b;i++)
#define repeq(i,a,b) for(int i=a;i<=b;i++)
#define repr(i,a,b) for(int i=a;i>b;i--)
#define repreq(i,a,b) for(int i=a;i>=b;i--)
#define leng(n) (int)(log10(n)+1)
#define INF 9000000000000000000
#define MOD 1000000007
#define PAI 3.14159265358979
// ver1.6
using namespace std;

int gcd(int a,int b){return b?gcd(b,a%b):a;}  //  最大公約数gcd
int lcm(int a,int b){return a/gcd(a,b)*b;}  //  最小公倍数lcm

signed main() {
  cout << fixed << setprecision(14);
  int n;
  cin >> n;
  string memo;
  Vi a(26,INF);
  rep(i,0,n){
    Vi b(26);
    cin >> memo;
    rep(j,0,memo.size()) b[memo[j]-'a']++;
    rep(j,0,26) a[j] = min(a[j],b[j]);
  }
  rep(i,0,26){
    rep(j,0,a[i]){
      char c = 'a' + i;
      cout << c;
    }
  }
  cout << endl;
  return 0;
}
