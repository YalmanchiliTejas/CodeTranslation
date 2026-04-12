// how many numbers from a to b with sum of digits = k?
// code inspired from : https://github.com/flash7even/Programming-Contest/blob/master/Code%20Repository/Dynamic%20Programming/Digit%20DP/Digit-DP.cpp

#include <bits/stdc++.h>
#define ll long long
using namespace std;

string s;
int dp[102][5][2], k;

ll dpsolve(int pos, int cnt, int f) {
    if (cnt > k) return 0;

    if (pos == (int)s.length()) {
        if (cnt == k) return 1;
        return 0;
    }

    if (dp[pos][cnt][f] != -1) return dp[pos][cnt][f];

    ll ans = 0; int lmt;

    if (f == 0) {
        // Digits we placed so far matches with the prefix of b
        // So if we place any digit > num[pos] in the current position, then the number will become greater than b
        lmt = s[pos] - '0';
    }
    else {
        // The number has already become smaller than b. We can place any digit now.
        lmt = 9;
    }

    // Try to place all the valid digits such that the number doesn't exceed b
    for (int dgt = 0; dgt <= lmt; dgt++) {
        int nf = f;
        int ncnt = cnt;
        if (dgt != 0) ncnt++;
        if (f == 0 && dgt < lmt) nf = 1; /// The number is getting smaller at this position
        if (ncnt <= k) ans += dpsolve(pos + 1, ncnt, nf);
    }

    return dp[pos][cnt][f] = ans;
}

int main() {
    cin >> s >> k;
    memset(dp, -1, sizeof(dp));
    ll res = dpsolve(0, 0, 0);
	cout << res << "\n";
	return 0;
}