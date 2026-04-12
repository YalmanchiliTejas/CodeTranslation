#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i ++)
using namespace std;
using ll = long long;
using PL = pair<ll,ll>;
using P = pair<int,int>;
constexpr int INF = 1000000000;
constexpr long long HINF = 1000000000000000;
constexpr long long MOD = 1000000007;// = 998244353;
constexpr double EPS = 1e-4;
constexpr double PI = 3.14159265358979;
const int coin[6] = {500,100,50,10,5,1};

int main() {
    int X,Y,Z; cin >> X >> Y >> Z;
    X -= Z;
    int ans = X/(Y + Z);
    cout << ans << '\n';
    return 0;
}