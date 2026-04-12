#include <algorithm>
#include <cassert>
#include <climits>
#include <cstdio>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

template <class T>
bool chmax(T &a, const T &b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
bool chmin(T &a, const T &b) {
    if (b < a) {
        a = b;
        return 1;
    }
    return 0;
}

const int INF = 1e9;
const long long LINF = 1e18;

int main() {
    int N, M;
    cin >> N >> M;

    set<pair<int, int>> edges;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        edges.insert(pair<int, int>(a, b));
    }

    vector<int> p(N - 1);
    for (int i = 0; i < N - 1; i++) {
        p[i] = i + 2;
    }

    long long cnt = 0;
    do {
        bool pass = true;
        int s = 1, e;
        for (int i = 0; i < p.size(); i++) {
            e = p[i];
            // cout << "s: " << s << ", e: " << e << endl;
            int minp = min(s, e);
            int maxp = max(s, e);
            if (edges.end() == edges.find(pair<int, int>(minp, maxp))) {
                pass = false;
                break;
            }
            s = e;
        }

        if (pass) {
            cnt++;
        }
        // cout << endl;
    } while (next_permutation(p.begin(), p.end()));

    cout << cnt << endl;

    return 0;
}
