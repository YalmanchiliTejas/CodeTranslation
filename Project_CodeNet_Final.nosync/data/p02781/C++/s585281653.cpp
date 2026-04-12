#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

long long ipow(int n, int m) {
    if (m == 0) return 1;
    if (m == 1) return n;
    return n * ipow(n, m - 1);
}


long long comb(int n, int r){
    vector<vector<long long> > v(n + 1, vector<long long>(r + 1, 0));
    for(int i = 0; i < n + 1; i++) {
        v[i][0] = 1;
        if (i < r + 1) {
            v[i][i] = 1;
        }
    }
    for(int i = 1; i < n + 1; i++) {
        for(int j = 1; j < min(i, r+1); j++) {
            v[i][j] = v[i - 1][j - 1] + v[i - 1][j];
        }
    }
    return v[n][r];
}


int count(string s, int k) {
    int msd = s[0] - '0';
    while (msd == 0) {
        s = s.substr(1);
        msd = s[0] - '0';
    }
    if (s.length() < k) {
        return 0;
    }
    if (k == 0) {
        return 1;
    }
    if (s.length() == k && k == 1) {
        return msd;
    }
    int sum = 0;
    if (s.length() > k) {
        sum += comb(s.length() - 1, k) * ipow(9, k);
    }
    for (int i = 1; i < msd; i++) {
        sum += comb(s.length() - 1, k - 1) * ipow(9, k - 1);
    }
    sum += count(s.substr(1), k - 1);

    return sum;
}

int main() {
    string s;
    int k;
    cin >> s;
    cin >> k;

    cout << count(s, k) << '\n';
    return 0;
}
