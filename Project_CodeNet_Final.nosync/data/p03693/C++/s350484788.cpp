#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <map>
using namespace std;

#define INF 1e9
#define LLINF 1e18
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;


int main() {
    int r, g, b, ans;
    cin >> r >> g >> b;
    ans = r * 100 + g * 10 + b;
    if (ans % 4 == 0) cout << "YES" << endl;
    else cout << "NO" << endl;
}