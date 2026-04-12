#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define mod 1000000007
using ll = long long;
using namespace std;
int main(){
  int a,b,c,x,y;
  cin >> a >> b >> c >> x >> y;
  ll ans = 0;
  if(a + b > c * 2){
    int minVal = min(x, y);
    ans += minVal * c * 2;
    x -= minVal;
    y -= minVal;
    if(a && a > c * 2){
      ans += c * x * 2;
    }else ans += x * a;
    if(b && b > c * 2){
      ans += c * y * 2;
    }else ans += y * b;
    cout << ans << endl;
  }else{
    ans += x * a;
    ans += y * b;
    cout << ans << endl;
  }
}