#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
    ll A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;
    ll ans = min(A*X+B*Y, 2*C*max(X,Y));
    if(X > Y) ans = min(ans, A*(X-Y)+2*C*Y);
    else ans = min(ans, B*(Y-X)+2*C*X);
    cout << ans << endl;
    return 0;
}