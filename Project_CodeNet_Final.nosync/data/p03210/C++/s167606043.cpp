#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <numeric>
#include <algorithm>
#define rep(it, ifrom, ito) for (auto it = ifrom; it != ito; ++it)
#define all(a) a.begin(), a.end()

using namespace std;

int main(int argc, char* argv[]) {
    const char* debug_env = getenv("DEBUG");
    const bool debug = debug_env && atoi(debug_env) != 0;

    int N;
    cin >> N;
    if (N == 3 || N == 5 || N == 7) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}

