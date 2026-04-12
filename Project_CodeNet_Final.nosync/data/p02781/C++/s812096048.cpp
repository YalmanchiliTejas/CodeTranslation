#include <list>
#include <map>
#include <set>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <memory.h>
#include <ctime>
#include <bitset>
#include <vector>
#include <string>
#include <queue>

using namespace std;

string s;
int d[111][3][5];

int dp(int pos, int f, int k) {
    if (pos == s.size() && k == 0) {
        return 1;
    }

    if (k < 0 || pos == s.size()) {
        return 0;
    }
    
    if (d[pos][f][k]) {
        return d[pos][f][k];
    }

    int ans = 0;
    int mx = s[pos] - 48;
    if (f == 0) {
        mx = 10;
    }
    for (int i = 1; i < mx; i++) {
        ans += dp(pos + 1, 0, k - 1);
    }
    if (f == 1) {
        if (mx) {
            ans += dp(pos + 1, 1, k - 1);
            ans += dp(pos + 1, 0, k);
        } else {
            ans += dp(pos + 1, 1, k);
        }
    } else {
        ans += dp(pos + 1, 0, k);
    }
    return d[pos][f][k] = ans;
}

void solution() {
    cin >> s;
    int k;
    cin >> k;
    cout << dp(0, 1, k) << endl;
}

/*-------------------*/

int main()
{
#ifdef Files
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    /*Test*/
    //freopen("input.txt", "w", stdout);

    double OcZ2X = clock();
#else
    //freopen("joke.in", "r", stdin);
    //freopen("joke.out", "w", stdout);
#endif

/*
　　     　 　          ∧_,,∧　　　
    　            ♪　  (・ω・)　♪
               ＿＿＿＿○＿＿つヾ＿＿＿＿＿
             /δ⊆・⊇ 。/†: :† /δ ⊆・⊇｡ /|
            |￣￣￣￣￣￣￣￣￣￣￣￣￣ | |
            |　　　*/solution();/* 　　| |
            |　　　　　　　　　　　　　 |
*/

#ifdef Time
    double P2HxQ = clock();
    printf("\n*** Total time = %.3f sec ***\n", (P2HxQ - OcZ2X) / CLOCKS_PER_SEC);
#endif
}