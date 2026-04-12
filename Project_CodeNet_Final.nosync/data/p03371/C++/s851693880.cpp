#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int Inf = 1000000000;
constexpr ll INF= 1e18;
constexpr ll MOD = 1000000007;
const double PI = 3.1415926535897;
typedef pair<ll,ll> P;

int main() {
    int A,B,C,X,Y;
    cin >> A >> B >> C >> X >> Y;
    C *= 2;
    int ret = Inf;
    for(int i = 0;i <= max(X,Y);i++) {
        int a = max(0,X - i);
        int b = max(0,Y - i);
        ret = min(ret,i * C + A * a + B * b);
    }
    cout << ret << endl;
}