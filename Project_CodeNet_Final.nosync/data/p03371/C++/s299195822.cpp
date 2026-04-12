#pragma GCC optimize("Ofast")
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define PI 3.141592
#define MOD7 1000000007
#define LL_INF 9000000000000000000
#define LL_MINF -9000000000000000000
#define INT_INF 2000000000
#define INT_MINF -2000000000
#define all(a) (a).begin(), (a).end()
#define fi first
#define se second
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

int main(){
    int A, B, AB, X, Y;
    cin >> A >> B >> AB >> X >> Y;
    ll ans = LL_INF;
    for(int Z = 0; Z <= 200000; Z+=2){
        ll money = Z * AB + max(X - Z / 2, 0) * A + max(Y - Z / 2, 0) * B;
        ans = min(ans, money);
    }
    cout << ans << endl;
}