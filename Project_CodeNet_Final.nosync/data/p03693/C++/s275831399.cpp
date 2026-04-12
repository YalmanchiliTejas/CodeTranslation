#include <bits/stdc++.h>
#define int long long
#define ALL(v) (v).begin(),(v).end()
#define pb push_back
#define rep(i,a,n) for(int i=a;i<n;i++)
#define repr(i,a,n) for(int i=a;i>n;i--)
#define leng(n) (int)(log10(n)+1)
#define INF 9000000000000000000
using namespace std;

int gcd(int a,int b){return b?gcd(b,a%b):a;}  //  最大公約数gcd
int lcm(int a,int b){return a/gcd(a,b)*b;}  //  最小公倍数lcm

signed main() {
  int a, b, c;
  cin >> a >> b >> c;
  if ( (100*a + 10*b + c) % 4 ==0) cout << "YES" << endl;
  else cout << "NO" << endl;
}