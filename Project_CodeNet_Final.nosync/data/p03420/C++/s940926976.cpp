//include
//------------------------------------------
#include <vector>
#include <list>
#include <map>
#include <unordered_map>
#include <climits>
#include <set>
#include <unordered_set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <queue>
#include <random>
#include <complex>
#include <regex>

using namespace std;

#define SHOW_VECTOR(v) {std::cerr << #v << "\t:";for(const auto& xxx : v){std::cerr << xxx << " ";}std::cerr << "\n";}
#define SHOW_MAP(v){std::cerr << #v << endl; for(const auto& xxx: v){std::cerr << xxx.first << " " << xxx.second << "\n";}}


int main() {

    long long N, K;
    cin >> N >> K;

    if (K == 0) {
        cout << N * N << endl;
        return 0;
    }

    long long ans = 0;
    for (long long b = 1; b <= N; b++) {
        long long d = N / b;
        ans += d * max(b - K, 0LL);
        if (N % b > 0) {
            ans += max(0LL, N % b - K + 1);
        }
    }

    cout << ans << endl;

}














































