
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
#include <locale>
#include <random>
#include <type_traits>

using namespace std;

#define SHOW_VECTOR(v) {std::cerr << #v << "\t:";for(const auto& xxx : v){std::cerr << xxx << " ";}std::cerr << "\n";}
#define SHOW_MAP(v){std::cerr << #v << endl; for(const auto& xxx: v){std::cerr << xxx.first << " " << xxx.second << "\n";}}

using LL = long long;

//~~~~~~~~~~~~~~~~~~~~~_(＾～＾ ｣ ∠)_~~~~~~~~~~~~~~~~~~~~~

constexpr LL INF = 1e10;

int main() {

    int N;
    cin >> N;

    vector<LL> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    reverse(A.begin(), A.end());

    vector<LL> dp(N, INF);

    for (int i = 0; i < N; i++) {
        auto it = lower_bound(dp.begin(), dp.end(), A[i] + 1);
        *it = A[i];
    }

    cout << lower_bound(dp.begin(), dp.end(), INF) - dp.begin();

}































