/// I am Ryuk..........


#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <chrono>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <string>
#include <tuple>
#include <utility>
#include <vector>
#include <iomanip>

#define ll long long
#define MAX 300005
#define pp pair<int,int>
#define pb push_back
#define mod 1000000007

using namespace std;

double dis(double x1, double y1, double x2, double y2) {
    return sqrt((abs(x2 - x1) * abs(x2 - x1)) + (abs(y1 - y2) * abs(y1 - y2)));
}

double parpendicular_dis(double x, double y, int m, double c) {
    double m1 = -1.0 / m;
    double new_x = (y - (m1 * x) - c) / 2.0 * m;
    double new_y = m * new_x + c;
    return dis(x, y, new_x, new_y);

}


ll maxx(ll a, ll b) {
    return (a > b) ? a : b;
}

ll mini(ll a, ll b) {
    return (a < b) ? a : b;
}

double reac(double XX, double YY) {
    if (XX < YY) {
        double temp = XX;
        XX = YY;
        YY = temp;
    }


    ll x1 = 0;
    ll y1 = 0;
    ll x2 = XX;
    ll y2 = YY;
    ll dif_X = abs(x1 - x2);
    ll dif_y = abs(y1 - y2);
    ll m = 1;
    double c;
    double xx, yy;
    if (dif_X >= dif_y) {
        double xxx = y2 - (y1 - (m * x1));
        double diff = abs(xxx - x2) / 2.0;
        xx = (double) x1 + diff;
        yy = y1;
    } else {
        assert(0);
    }
    c = yy - m * xx;
    double d1 = parpendicular_dis(x1, y1, m, c);
    double d2 = parpendicular_dis(x2, y2, m, c);
    if (d1 != d2) {
        assert(0);
    }
    return d1;
}

bool comp(pair<ll, ll> a, pair<ll, ll> b) {
    return (a.second / a.first) < (b.second / b.first);
}


int main() {
    int n;
    cin >> n;
    ll arr[n];
    for (int i = 0; i < n; i++)cin >> arr[i];

    ll dp[n][n][2];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j][1] = dp[i][j][0] = 0;
        }
    }

    for (int l = 1; l <= n; l++) {
        for (int i = 0; i < n; i++) {
            int j = i + l - 1;
            if (j >= n) continue;
            if (i == j) {
                dp[i][j][0] = arr[i];
                dp[i][j][1] = -arr[i];
                continue;
            }
            if (i > j) {
                dp[i][j][0] = 0;
                dp[i][j][1] = 0;
                continue;
            }
            dp[i][j][0] = maxx(arr[i] + dp[i + 1][j][1], arr[j] + dp[i][j - 1][1]);
            dp[i][j][1] = mini(-arr[i] + dp[i + 1][j][0], -arr[j] + dp[i][j - 1][0]);
        }
    }
    cout << (dp[0][n - 1][0]) << endl;

}

/*
    1
    14
    0 0
    10 1
    10 2
    10 3
    10 4
    10 5
    10 6
    10 7
    10 8
    10 9
    10 11
    10 12
    10 13
    10 14
    */



