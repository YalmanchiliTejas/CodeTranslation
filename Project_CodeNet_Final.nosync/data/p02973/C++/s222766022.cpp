#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

using namespace std;

typedef long long ll;

template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

vector<int> as;

int solve(const int N) {
    // {value, count}
    multiset<pair<int, int>> ms;

    for (auto &a : as) {
        auto it = ms.upper_bound({a, 0});
        pair<int, int> item;
        if (it == ms.begin()) {
            item = {a, 1};
            ms.insert(item);
        // } else if (it == ms.end()) {
        //     item = {a, 1};
        //     ms.insert(item);
        } else {
            it--;
            item = *it;
            ms.erase(it);
            item.first = a;
            item.second++;
            ms.insert(item);
        }
        // printf("added: {%d, %d}\n", item.first, item.second);
    }

    return (int) ms.size();
}

int main(void) {
    int N;
    cin >> N;

    as.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> as[i];
    }

    cout << solve(N) << endl;

    return 0;
}
