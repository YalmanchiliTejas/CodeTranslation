#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define sc(x) scanf("%lld",&x);
int main(){
    ll a, b, c, x, y, ans = 0;
    sc(a) sc(b) sc(c) sc(x) sc(y)
    while (x > 0 && y > 0 && a + b > 2*c){
        x -= 1; y -= 1;
        ans += 2*c;
    }
    ans += min(a*x, 2*x*c);
    ans += min(b*y, 2*y*c);
    cout << ans << endl;
    return 0;
}