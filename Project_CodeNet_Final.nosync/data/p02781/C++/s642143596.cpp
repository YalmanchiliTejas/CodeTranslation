#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

using ll = long long;

vector<int> toVec(string x) {
    vector<int> v;
    int n = x.size();
    for (auto c : x) {
        v.push_back(c - '0');
    }
    return v;
}

ll generar(int prof, int n, bool tight, int k, const vector<int>& digitos, vector<vector<vector<int>>>& dp) {
    if (prof == n) {
        // Acabé de generar un número
        return k == 0;
    }
    if (k < 0) {
        return 0;
    }
    if (dp[prof][k][tight] != -1) return dp[prof][k][tight];
    // tight: representa si cuento hasta 9 o solo hasta el dígito actual
    // true si el número está "ajustado" (solo llega hasta el dígito actual)
    int limSup = tight ? digitos[prof] : 9;
    ll ans = 0;
    for (int d = 0; d <= limSup; d++) {
        ans += generar(prof + 1, n, tight && (d == digitos[prof]), d > 0 ? k - 1: k, digitos, dp);
    }
    return dp[prof][k][tight] = ans;
}

int main() {
    string num;
    int k;
    cin >> num >> k;
    vector<int> digitos = toVec(num);
    vector<vector<vector<int>>> dp(digitos.size() + 1, vector<vector<int>>(k + 1, vector<int>(2, -1)));
    ll ans = generar(0, digitos.size(), true, k, digitos, dp);
    cout << ans << "\n";
}