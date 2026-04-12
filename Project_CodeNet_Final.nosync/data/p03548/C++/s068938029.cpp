#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

 

int main() {
    ll X, Y, Z;
    cin >> X >> Y >> Z;
    int ans = 0;
    X -= Z;
    ans += X / (Y + Z);
    cout << ans << endl;
}
