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
  int n;
  cin >> n;
  vector<int> o(0),e(0);
  int memo;
  
  rep(i,0,n){
    if(i%2 == 0){
      cin >> memo;
      o.pb(memo);
    }
    else{
      cin >> memo;
      e.pb(memo);
    }
  }
  
  if(n%2==0) {
    reverse(ALL(e));
    rep(i,0,o.size()){
      e.pb(o[i]);
    }
    rep(i,0,n-1){
      cout << e[i] << ' ';
    }
    cout << e[n-1] << endl;
    return 0;
  }
  else {
    reverse(ALL(o));
    rep(i,0,e.size()){
      o.pb(e[i]);
    }
    rep(i,0,n-1){
      cout << o[i] << ' ';
    }
    cout << o[n-1] << endl;
    return 0;
  }
  
  
}
