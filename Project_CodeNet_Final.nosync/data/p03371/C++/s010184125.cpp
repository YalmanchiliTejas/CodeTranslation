#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<(n);++i)
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
int gcd(int a,int b) { return b ? gcd(b,a%b) : a;}
int lcm(int a,int b) { return a/gcd(a,b)*b;}
void printb(unsigned int v) {
  unsigned int mask = (int)1 << (sizeof(v) * CHAR_BIT - 1);
  do putchar(mask & v ? '1' : '0');
  while (mask >>= 1);
}
void putb(unsigned int v) {putchar('0'), putchar('b'), printb(v), putchar('\n');}
#define ALL(W) (W).begin(),(W).end()

signed main(){
  int A,B,C,X,Y,ans=100000000000;
  cin >> A >> B >> C >> X >> Y;
  for(int i=0;i<=max(X,Y);i++){
    if(X>=i && Y>=i) chmin(ans,A*(X-i)+B*(Y-i)+2*C*i);
    else if(X>=i && Y<i) chmin(ans,A*(X-i)+2*C*i);
    else chmin(ans,B*(Y-i)+2*C*i);
  }
  cout << ans << endl;
  return 0;
}
