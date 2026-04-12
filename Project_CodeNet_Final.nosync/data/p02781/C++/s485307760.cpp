#include <iostream>
using namespace std;

long long memo[101][4];
long long calc(string &s, int i, int k) {
    if (memo[i][k] >= 0) return memo[i][k];
    if (i == s.size()) return memo[i][k] = (k == 0 ? 1 : 0);
    if (k == 0) return memo[i][k] = 1;
    long long ret = 0;
    if (s[i] != '0') {
        // 0 < d < s[i]
        long long n = s.size() - i - 1;
        if (k == 1) ret += (s[i] - '1');
        else if (k == 2) ret += (s[i] - '1') * n * 9;
        else ret += (s[i] - '1') * n * (n - 1) / 2 * 81;
        // s[i] (> 0)
        ret += calc(s, i+1, k-1);
        // 0
        if (k == 1) ret += n * 9;
        else if (k == 2) ret += n * (n - 1) / 2 * 81;
        else ret += n * (n - 1) * (n - 2) / 6 * 729;
    } else {
        ret += calc(s, i+1, k);     // 0
    }
    
    return memo[i][k] = ret;
}

int main() {
    string s; int k;
    cin >> s >> k;
    for (int i = 0; i < 100; i++) for (int j = 0; j < 4; j++) memo[i][j] = -1;
    cout << calc(s, 0, k) << endl;
}
