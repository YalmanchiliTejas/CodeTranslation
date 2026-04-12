#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

const ll INF = 1LL << 60;

ll A, B, C, X, Y;
int main() {
    cin >> A >> B >> C >> X >> Y;

    ll ans = INF;

    // AB を固定する
    ll limit = max(X * 2, Y * 2);
    for (int i = 0; i <= limit; i += 2) {
       ll cost = 0;  
       ll half = i / 2;

       // AB ピザ
       cost += i * C;

       // X 揃える (A ピザ)
       cost += max(X - half, 0LL) * A; 

       // Y 揃える (B ピザ)
       cost += max(Y - half, 0LL) * B; 

       ans = min(ans, cost);
    }
    cout << ans << endl;
}