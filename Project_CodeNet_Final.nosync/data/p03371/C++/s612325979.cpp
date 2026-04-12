#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < n; i++)

typedef long long ll;
using namespace std;
int mod = 1000000007;

int main(void){
    int A, B, C; cin >> A >> B >> C;
    int ans = mod+mod;
    int X, Y; cin >> X >> Y;
    int mx_ab = max(X, Y)*2;
    for(int ab = 0; ab <= mx_ab; ab+=2){
        int lack_a = max(0, X - ab/2);
        int lack_b = max(0, Y - ab/2);
        ans = min(ans, ab*C + lack_a*A + lack_b*B);
    }
    cout << ans << endl;
    return 0;
}