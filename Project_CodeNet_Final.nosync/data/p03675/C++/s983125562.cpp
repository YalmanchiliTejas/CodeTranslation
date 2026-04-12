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

    deque<int> Q;

    if (N % 2 == 0) {
        for (int i = 1; i <= N; i++) {
            if (i % 2 == 0) Q.push_back(a[i-1]);
            if (i % 2 == 1) Q.push_front(a[i-1]);
        }
    }
    if (N % 2 == 1) {
        for (int i = 1; i <= N; i++) {
            if (i % 2 == 0) Q.push_front(a[i-1]);
            if (i % 2 == 1) Q.push_back(a[i-1]);
        }
    }

    vector<int> ans;
    while (!Q.empty()) {
        int d = Q.back();
        Q.pop_back();
        ans.push_back(d);
    }

    for (auto x : ans) cout << x << " ";

    return 0;
}



























































