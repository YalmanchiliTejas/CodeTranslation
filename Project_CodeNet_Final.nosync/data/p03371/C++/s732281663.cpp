#include <bits/stdc++.h>

#define rep(i, N) for (int i = 0; i < N; i++)
#define rep1(i, N) for (ll i = 1; i <= N; i++)
#define repr(i, N) for (ll i = N-1; i >= 0; i--)
#define repr1(i, N) for (ll i = N; i > 0; i--)

using ll = long long;
using namespace std;

int main(){
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;

    ll ans = 0;
    ans = min(A*X + B*Y, min(C*2*min(X,Y) + ((X > Y) ? A*(X-Y) : B*(Y-X)),C*2*max(X,Y)));
    
    cout << ans << endl;
}
