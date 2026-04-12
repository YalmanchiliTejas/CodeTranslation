#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) (v).begin(),(v).end()
#define out(a) cout << (a) << endl
using namespace std;
using ll = long long;
int main(){
    int a, b, c, x, y;
    int ans=0;
    cin >> a >> b >> c >> x >> y;
    ans = a * x + b * y;
    for (int i=0; i<=max(x, y); i++){
        ans = min(ans, a*max(0, x-i) + b*max(0, y-i) + 2 * c * i);
    }
    out(ans);
}