#include <bits/stdc++.h>
#define int long long
#define ALL(v) (v).begin(),(v).end()
#define pb push_back
#define rep(i,a,b) for(int i=a;i<b;i++)
#define repr(i,a,b) for(int i=a;i>b;i--)
#define leng(n) (int)(log10(n)+1)
#define INF 9000000000000000000
using namespace std;

int gcd(int a,int b){return b?gcd(b,a%b):a;}  //  最大公約数gcd
int lcm(int a,int b){return a/gcd(a,b)*b;}  //  最小公倍数lcm

signed main() {
  
  int x,y,z;
  cin >> x >> y >> z;
  
  int a,b;
  cin >> a >> b;
  int minn = min(a,b);
  a -= minn;
  b -= minn;
  
  int ans = 0;
  ans += minn * min(x+y,2*z);
  
  if(b==0){
    ans += a * min(x,2*z);
  }
  else {
    ans += b * min(y,2*z);
  }
  
  cout << ans << endl;
}
