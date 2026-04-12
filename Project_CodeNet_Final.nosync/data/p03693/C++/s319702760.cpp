#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <array>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define loop(i, a, n) for (int i = a; i < (n); i++)
#define all(in) in.begin(), in.end()
#define INF 1e9
#define MOD 1e9 + 7
int main() {
    int r, g, b;
    cin >> r >> g >> b;
    int ans = (100 * r + 10 * g + b) % 4;
    cout << (ans == 0 ? "YES" : "NO") << endl;
    return 0;
}