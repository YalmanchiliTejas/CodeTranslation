#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll ZERO = 0;
const ll INF = 1e14;
const ll MOD = 1000000007;
const double PI = 3.1415926535897;

ll N,X;
ll lv[60];
ll P[60];

ll f(ll a,ll b) {
    if(a == 0) {
        if(b <= 0) {
            return 0;
        }
        else {
            return 1;
        }
    }
    else if(b <= 1 + lv[a - 1]) {
        return f(a - 1,b - 1);
    }
    else {
        return P[a - 1] + 1 + f(a - 1,b - 2 - lv[a - 1]);
    }
}

int main() {
    cin >> N >> X;
    lv[0] = 1;
    P[0] = 1;
    for(int i = 1;i <= N;i++) {
        lv[i] = 3 + lv[i - 1] * 2;
        P[i] = 1 + P[i - 1] * 2;
    }
    cout << f(N,X) << endl;
}