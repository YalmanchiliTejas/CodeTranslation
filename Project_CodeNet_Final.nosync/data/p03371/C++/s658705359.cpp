#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define repa(i, s, n) for(int i = s; i < (int)n; i++)
using namespace std;
using ll = long long;
typedef vector<int> vi;


signed main() {
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    long long ans;
    if(a+b <= 2*c){
        ans = x*a + y*b;
    }else{
        if(x > y){
            int ans1 = 2*c*y + a*(x-y);
            int ans2 = 2*c*x;
            ans = min(ans1, ans2);
        }else{
            int ans1 = 2*c*x + b*(y-x);
            int ans2 = 2*c*y;
            ans = min(ans1, ans2);
        }
    }
    cout << ans << endl;
}