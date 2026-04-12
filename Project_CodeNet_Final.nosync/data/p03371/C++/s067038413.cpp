#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll INFL = 1000000000000000010;//10^18 = 2^60
int INF = 2147483600;//10^9
ll MOD  = 1000000007;
double m = 0.00000001;
int main(void){
    ll A,B,C;
    cin >> A >> B >> C;
    ll X,Y;
    cin >> X >> Y;
    ll ans = INFL;
    for(int i = 0; i < 200010; i += 2){
        int x = X - i/2;
        int y = Y - i/2;
        x = max(x, 0);
        y = max(y, 0);
        ans = min(ans, i * C + x * A + y * B);
    }
    cout << ans << endl;
}
