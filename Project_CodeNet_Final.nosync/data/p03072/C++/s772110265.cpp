#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <cstdio>
#include <algorithm>
#include <functional>
#include <string>
#include <numeric>
#include <stack>
#include <cstdlib>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
//typedef pair<int, int> P;

#define rep(i, a, N) for(int i = a; i < N; i++)
#define rrep(i, a, N) for(int i = a; i >= N; i--)

int main() {
    int n;
    cin >> n;

    vector<int> h(n);
    rep(i, 0, n) cin >> h[i];

    int ans = 1;
    int tallest = h[0];
    rep(i, 1, n) {
        if (h[i] >= tallest) ans++;
        tallest = max(tallest, h[i]);
    }
    cout << ans << endl;
}