#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <set>
#include <stack>
#include <numeric>
#include <chrono>
#include <bitset>
#include <tuple>
#include <queue>
#include <map>
#include <cstring>
#include <cassert>
#include <math.h>
using namespace std;

const int N = 2e5 + 10, mod = 1e9 + 7;


int main() {
    // ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int tc = 1;
    // scanf("%d", &tc);
    for(int cn = 1; cn <= tc; cn++) {
        int x; cin >> x;
        puts(x >= 30 ? "Yes" : "No");
    }
    return 0;
}