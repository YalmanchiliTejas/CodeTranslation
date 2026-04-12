#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int A, B, C;
    int X, Y;
    cin >> A >> B >> C;
    cin >> X >> Y;
    ll INF = 1LL << 60;
    ll MIN = INF;
    for (int i = 0; i <= 2*max(X, Y); i += 2) {
        ll money = 0; int ab = i/2;
        money += C*i;
        if (X-ab > 0) money += A*(X-ab);
        if (Y-ab > 0) money += B*(Y-ab);
        MIN = min(MIN, money);
    }
    cout << MIN << endl;
    return 0;
}