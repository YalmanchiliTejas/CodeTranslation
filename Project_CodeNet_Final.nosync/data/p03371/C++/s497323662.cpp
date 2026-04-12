#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<n; i++)
typedef long long int ll;
typedef pair<int, int> P;
#define INF 1e9 + 7

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    
    int ans = 0;
    
    if(a + b > 2 * c){
        if(x > y){
            ans += y * 2 * c;
            ans += (x - y) * a;
        }else{
            ans += x * 2 * c;
            ans += (y - x) * b;
        }
        
        ans = min(max(x, y) * 2 * c, ans);
    }else{
        ans += a * x;
        ans += b * y;
    }
    
    cout << ans << endl;

    return 0;
}