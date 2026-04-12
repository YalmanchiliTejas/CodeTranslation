#include <bits/stdc++.h>

using namespace std;

long long prime = 1000000007;

bool all_chars_equal(string s) {
    for (char c : s) {
        if (c != s[0]) {
            return false;
        }
    }
    return true;
}

vector<int> get_runs(string s) {
    vector<int> runs;
    int current_run = 0;
    for (char c : s) {
        if (c == s[0]) {
            ++current_run;
        } else if (current_run > 0) {
            runs.push_back(current_run);
            current_run = 0;
        }
    }
    // We intentionally don't add the last run
    return runs;
}

long long mod(long long x) {
    return (x % prime + prime) % prime;
}

long long f(int n, int k) {
    vector<long long> pow_2(2 * k + 4);
    pow_2[0] = 1LL;
    for (int i = 1; i < 2 * k + 4; ++i) {
        pow_2[i] = pow_2[i - 1] * 2 % prime;
    }

    vector<long long> f1(max(n + 1, 2 * k + 4), 0);
    for (int i = 1; i <= k; ++i) {
        f1[i] = pow_2[i];
    }
    f1[k + 1] = mod(pow_2[k+1] - 1);
    for (int n1 = k + 2; n1 <= 2 * k + 3; ++n1) {
        f1[n1] = mod(pow_2[n1] - 1 - n1 * pow_2[n1 - k - 2]);
    }
    for (int n1 = 2 * k + 4; n1 <= n; ++n1) {
        f1[n1] = mod(2 * f1[n1 - 1] - f1[n1 - k - 2]);
    }
    return f1[n];
}

/*
f(n, k) = antal cirkler af længde n med højst k røde i streg (ingen andre begrænsninger)

f(n, k) = 2^n for n <= k
f(n, k) = 2^n - 1 for n = k+1
f(n, k) = 2^n - 1 - n * 2^{n-k-2} for k+2 <= n <= 2k+3
f(n, k) = 2f(n-1, k) - f(n-k-2, k) for n >= 2k + 4

*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    string s;
    cin >> n >> m;
    cin >> s;
    if (all_chars_equal(s)) {
        cout << f(n, 1) << endl;  // OK since n >= 2
        return 0;
    }
    if (n % 2 != 0) {
        cout << 0 << endl;
        return 0;
    }
    vector<int> runs = get_runs(s);
    int bound = runs[0] % 2 == 1 ? runs[0] : runs[0] + 1;
    bound = min(bound, n - 1);
    for (int run : runs) {
        if (run % 2 == 1 && run < bound) {
            bound = run;
        }
    }
    cout << mod(f(n / 2, (bound - 1) / 2) * 2) << endl;
    return 0;
}
