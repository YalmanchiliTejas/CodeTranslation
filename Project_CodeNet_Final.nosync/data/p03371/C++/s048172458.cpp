#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using namespace std;
template <typename T> using vec = std::vector<T>;

int main() {
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;
    int c1 = A*X+B*Y;
    int c2 = max(X,Y)*C*2;
    int c3;
    if(X>Y) c3=Y*C*2+(X-Y)*A;
    else c3=X*C*2+(Y-X)*B;
    cout << min({c1,c2,c3}) << endl;
}
