#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

static const int MAX = 1e6;
static const int NIL = -1;
static const ll INF = 1<<21;
static const ll MOD = 1e9 + 7;

bool compPair(const pair<int, int>& arg1, const pair<int, int>& arg2) {
    return arg1.first > arg2.first;
}

int main() {
    int N;
    cin >> N;

    vector<int> A(N);
    for(int i=0;i<N;i++) {
        cin >> A.at(i);
    }

    multiset<int> mset;

    int now;
    for(int i=0;i<N;i++) {
        now = A.at(i);
        auto itr = mset.lower_bound(now);
        if (itr!=mset.begin()) mset.erase(--itr);
        mset.insert(now);
    }

    cout << mset.size() << endl;
    return 0;
}
