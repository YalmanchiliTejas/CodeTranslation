#include <iostream>
#include <cctype>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <utility>
#include <string>
#include <functional>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
typedef long long ll;
const int INF = 100000000, mod = 1000000007;
const ll LLINF = 1LL << 50;
using namespace std;


int main() {
    int x, y, z;
    cin >> x >> y >> z;
    cout << (x - z) / (y + z) << endl;
    return 0;
}