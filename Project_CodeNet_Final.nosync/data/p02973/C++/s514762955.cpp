
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

int main() {

    int N;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    multiset<int> mst;
    for (int i = 0; i < N; i++) {
        auto it = mst.lower_bound(A[i]);
        if (it == mst.begin()) {
            mst.insert(A[i]);
        } else {
            it--;
            mst.erase(it);
            mst.insert(A[i]);
        }
    }

    cout <<mst.size() << endl;

}






















