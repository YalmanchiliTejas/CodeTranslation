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
    
    int ans = INF;
    
    rep(i, max(x, y) + 1){
        ans = min(ans, 2 * c * i + max(0, x - i) * a + max(0, y - i) * b);
    }
    
    cout << ans <<endl;

    return 0;
}