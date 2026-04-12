//全探索（nC2個の組み合わせをすべて調べる）
#include <bits/stdc++.h>
#define FOR(i, l, r) for(ll i = l; i < (ll)(r); i++)
#define rep(i, N) FOR(i, 0, N)
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
typedef vector<int> vi;
typedef vector<ll> vl;
const ll MOD = 1000000007LL;

int A[105][105];

int main() {
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;
    
    ll ans = 0;
    if(X < Y) {
        if(A+B > 2*C) ans += C*2*X;
        else ans += (A+B)*X;
        Y -= X; X = 0;
    }else{
        if(A+B > 2*C) ans += C*2*Y;
        else ans += (A+B)*Y;
        X -= Y; Y = 0;
    }
    if(X > 0){
        if(A > 2*C) ans += 2*C*X;
        else ans += A*X;
    }
    if(Y > 0){
        if(B > 2*C) ans += 2*C*Y;
        else ans += B*Y;
    }

    cout << ans << "\n";
    return 0;
}
