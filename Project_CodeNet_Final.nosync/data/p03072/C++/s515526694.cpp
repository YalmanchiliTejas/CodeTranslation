#include <iostream>
#include <algorithm>
#include <map>
#include <utility>
#include <vector>
#include <cstdio>
#include <iomanip>
#include <cmath>
using namespace std;
using ll = long long;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep1(i, n) for(int i = 1; i <= n; i++) 

int main() {
    int N, H[20];
    cin >> N;
    rep(i,N) cin >> H[i];

    int ans = 1;
    int highest = H[0];
    for (int i = 1; i < N; i++) {
        if (H[i] >= highest) {
            ++ans;
            highest = H[i];
        }
    }
    cout << ans << endl;
    return 0;
}