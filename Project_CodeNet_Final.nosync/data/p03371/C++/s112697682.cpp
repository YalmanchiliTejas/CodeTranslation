#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;

void solve(long long A, long long B, long long C, long long X, long long Y){
    long long ans = INF;
    for(long long i = 0; i <= 100000; ++i){
        ans = min(ans, i * 2 * C + max(0LL, X-i) * A + max(0LL, Y-i) * B);
    }
    cout << ans << endl;
    return;
}


int main(){
    long long A;
    scanf("%lld",&A);
    long long B;
    scanf("%lld",&B);
    long long C;
    scanf("%lld",&C);
    long long X;
    scanf("%lld",&X);
    long long Y;
    scanf("%lld",&Y);
    solve(A, B, C, X, Y);
    return 0;
}
