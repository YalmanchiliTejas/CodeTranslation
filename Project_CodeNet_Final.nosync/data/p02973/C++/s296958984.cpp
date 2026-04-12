#include <algorithm>
#include <iostream>
#include <limits>
#include <numeric>
#include <queue>
#include <set>
#include <vector>

#define rep(i, x, n) for(int i = x; i < n; i++)
using namespace std;
const long long INF = 1LL << 60;
bool compare_by_b(pair<int, long long> a, pair<int, long long> b) {
    if(a.second != b.second) {
        return a.second < b.second;
    } else {
        return a.first < b.first;
    }
}

int main() {
    int N;
    cin >> N;
    vector<long long> A(N);
    rep(i, 0, N) { cin >> A[i]; }
    multiset<long long> se;
    rep(i, 0, N) {
        long long t = A[i];
        auto ite = se.lower_bound(t);
        if(ite != se.begin()) {
            se.erase((--ite));
        }
        se.insert(t);
    }
    cout << se.size() << endl;
}