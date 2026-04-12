#include <bits/stdc++.h>

#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    using namespace std;
    const ll mod = 1'000'000'007;
    string k;
    cin >> k;
    int d;
    cin >> d;
    vector< vector<int> > A(k.size() + 1, vector<int>(d, 0));
    A[0][0] = 1;
    for(int i = 1; i < k.size(); i++) {
        for(int j = 0; j < d; j++)
            for(int q = 0; q < 10; q++)
                A[i][(j + q) % d] = (A[i][(j + q) % d] + A[i - 1][j]) % mod;
    }
    /*
    for(int i = 0; i < k.size(); i++) {
        for(int j = 0; j < d; j++)
            cout << A[i][j] << " ";
        cout << "\n";
    }
    */
    ll result = 0;
    int up = 0;
    for(int i = 0; i < k.size(); i++) {
        int m = k[i] - '0';
        for(int j = (i == 0 ? 1 : 0); j < m; j++)
            result = (result + A[k.size() - i - 1][(3 * d - up - j) % d]) % mod;
        up = (up + m) % d;
    }
    result = (result + (up == 0) + A[k.size() - 1][0] - 1) % mod;
    cout << result << "\n";

    return 0;
}
