#include <cstdio>
#include <iostream>
#include <cassert>
#include <string>
#include <algorithm>
#include <cstring>
#include <utility>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <cmath>
#include <deque>
#include <unordered_map>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
const int MAXN = 456789;
const int INF = (int)1e9;
vector<int> line[MAXN];

int main() {
    int N;
    scanf("%d", &N);
    vector<pii> V;
    int mx = 0, mn = INF;
    for (int i = 0; i < N; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        if (x > y) swap(x, y);
        V.push_back(make_pair(x, y));
        mn = min(x, mn);
        mx = max(y, mx);
    }
    sort(V.begin(), V.end());
    int mxL = mx, mnR = mn;
    multiset<int> st;
    for (int i = 0; i < N; i++) {
        mxL = min(mxL, V[i].second);
        mnR = max(mnR, V[i].first);
        st.insert(mnR);
    }
    LL ans = ((LL)mx - mxL) * ((LL)mnR - mn);
    LL len = (mx - mn);
    for (int i = 0; i < N; i++) {
        LL x = V[i].first, y = V[i].second;
        st.erase(st.find(x));
        st.insert(y);
        ans = min(ans, len * (*st.rbegin() - *st.begin()));
    }
    printf("%lld\n", ans);
    return 0;
}
