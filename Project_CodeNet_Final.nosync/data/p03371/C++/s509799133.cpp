/*
  Author: Hamza Hasbi
*/
#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define ull unsigned long long
#define uld unsigned long double
#define ui unsigned int
#define ud unsigned double
#define uf unsigned float
#define pi 2*acos(0.0)
#define module cin.ignore()
#define rep(i,l,r) for(auto i=l;i<=r;i++)
#define range(x,y) for(auto x:y)
//inline long long lcm(ll a,ll b) {return a*b/__gcd(a,b);}
//inline long long gcd(ll a,ll b) {return 1LL*b == 0 ? a : gcd(1LL*b, a*1LL % b*1LL);}
using namespace std;
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    int ans = 0;
    int curr = min(x, y);

    if(a + b <= 2 * c) {
      ans += curr * (a);
      ans += curr * (b);
      x -= curr;
      y -= curr;
    }
    else {
      ans += 2 * curr * c;
      x -= curr;
      y -= curr;
    }

    ans += min(2 * c, a) * x;
    ans += min(2 * c, b) * y;

    cout << ans << endl;
    return 0;
}
