#include<bits/stdc++.h>
using namespace std;

int main() {
    long long A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;
    long long ans = 10000000000;
    for (long long i=0; i<100010; i++) {
        long long m = i*2*C+max((long long)0, X-i)*A+max((long long)0, Y-i)*B;
        ans = min(ans, m);
    }
    cout << ans << endl;
}