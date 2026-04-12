#include <bits/stdc++.h>
using namespace std;

#define INF 1e9
#define LLINF 1e18
#define pi 3.14159265358979323
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;

int gcd(int a, int b) {
    if(a % b == 0) {
        return b;
    }
    else {
        return(gcd(b, a % b));
    }
}


int main() {
    int n, k;
    string s;
    cin >> n >> s >> k;
    char a;
    a = s.at(k - 1);
    string ans;
    rep(i, n) {
        if (s.at(i) == a) {
            ans += a;
        }
        else ans += '*';
    }
    cout << ans << endl;
}