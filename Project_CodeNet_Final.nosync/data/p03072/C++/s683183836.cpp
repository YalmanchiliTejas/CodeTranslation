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
  int N;
  cin >> N;
  int a[N]={},ans=1;
  rep(i,N) cin >> a[i];
  int maxi=a[0];
  for(int i=0;i<N-1;i++){
    chmax(maxi,a[i]);
    if(maxi<=a[i+1]) ans++;
  }
  cout << ans << endl;
  return 0;
}
