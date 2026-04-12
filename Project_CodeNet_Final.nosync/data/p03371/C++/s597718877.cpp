#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define rep(i, n, s) for (int i = s; i < (int)(n); i++)

ll calcNumOfCombination(ll n, ll r) {
    ll num = 1;
    for (ll i = 1; i <= r; i++) {
        num = num * (n - i + 1) / i;
    }
    return num;
}

int gcd(int x, int y) { return (x % y) ? gcd(y, x % y) : y; }

int findSumDigits(int s) {
    int num = 0;
    int temp = 0;
    while (s) {
        temp = s % 10;
        num += temp;
        s = s / 10;
    }
    return num;
}

int countDivisorNum(int n) {
    int count = 0;
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            count++;
        }
    }
    return count;
}

int main() {
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    int ansA = 0, ansB = 0, ansC = 0;
    int ans;

    ansA = a * x + b * y;
    ansB = 2 * c * max(x, y);
    ans = min(ansA, ansB);
    if (x >= y) {
        ansC = 2 * c * min(x, y) + a * (x - y);
    } else {
        ansC = 2 * c * min(x, y) + b * (y - x);
    }
    ans = min(ans, ansC);

    cout << ans << endl;


    return 0;
}