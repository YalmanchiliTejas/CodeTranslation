#pragma optimize ("O3")
#include <bits/stdc++.h>

using namespace std;

using ll = long long;

bool is_prime(int n) {
    if (n % 2 == 0) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return n != 1;
}

vector<int> divisor(int n) {
    vector<int> res;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            res.emplace_back(i);
            if (i != n / i) res.emplace_back(n / i);
        }
    }
    return res;
}

map<int, int> prime_factor(int n) {
    map<int, int> res;
    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            ++res[i];
            n /= i;
        }
    }
    if (n != 1) res[n] = 1;
    return res;
}

vector<int> sieve(int n) {
    vector<int> res;
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = false;
    is_prime[1] = false;
    for (int i = 2; i <= n; i++) {
        if (!is_prime[i]) continue;
        res.emplace_back(i);
        for (int j = 2 * i; j <= n; j += i) is_prime[j] = false;
    }
    return res;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<ll> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    vector< vector<int> > vv(n);
    //int counter = 0;
    for (int i = 1; i < n - 1; i++) {
        for (int j = i; j < n; j += i) {
            vv[j].push_back(i);
            //counter++;
        }
    }
    //cerr << counter << endl;

    ll ans = 0;
    for (int x = 1; x < n - 2; x++) {
        int y = x;
        ll sum = 0;
        while (y < n) {
            int z = n - 1 - y;
            int a = z, b = z - x;
            if (b <= 0 || a <= b || (a % x == 0 && a / x <= (n - 1 - a) / x)) break;
            sum += s[y] + s[z];
            ans = max(ans, sum);
            y += x;
        }
    }
    cout << ans << endl;
    return 0;
}