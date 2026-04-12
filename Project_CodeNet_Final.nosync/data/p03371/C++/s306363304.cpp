#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n); i++)
typedef long long ll;

int main() {
    int A,B,C,X,Y; 
    cin >> A >> B >> C >> X >> Y;
    ll ans = 10000000000;
    for(int i = 0; i <= 100000; i++){
        ll res = i*2*C + max(0,X-i)*A + max(0,Y-i)*B;
        ans = min(ans,res);
    }
    cout << ans << endl;
}