//include
//------------------------------------------
#include <vector>
#include <list>
#include <map>
#include <climits>
#include <set>
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

    int N;
    cin >> N;

    vector<int> a(N);
    for (int i = 0; i < N; i++) cin >> a[i];

    vector<int> p_a(N + 1, 0);
    for (int i = 0; i < N; i++) p_a[i + 1] += p_a[i] + a[i];

//    SHOW_VECTOR(p_a);

    int ans = 0;
    for (int i = 1; i <= 100; i++) {
        bool good = true;
        for (int j = 1; j <= N; j++) if (i * j > p_a[j]) good = false;
        if (good) ans = max(ans, i);
    }

    cout << ans << endl;

}










