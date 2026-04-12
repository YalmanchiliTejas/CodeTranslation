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
const int MAXN = 123456;
int x[MAXN], y[MAXN];
int idxx[MAXN], idxy[MAXN];
bool visit[MAXN];

int main() {
    int N;
    scanf("%d", &N);
    vector<pii> candx, candy;
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &x[i], &y[i]);
        candx.push_back(make_pair(x[i], i));
        candy.push_back(make_pair(y[i], i));
    }
    sort(candx.begin(), candx.end());
    sort(candy.begin(), candy.end());
    for (int i = 0; i < N; i++) {
        idxx[candx[i].second] = i;
        idxy[candy[i].second] = i;
    }
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    LL ans = 0;
    pq.push(make_pair(0, candx[0].second));
    while (!pq.empty()) {
         auto tp = pq.top();
         pq.pop();
         int cur = tp.second;
         //printf("cur = %d w = %d\n", cur, tp.first);
         if (visit[cur]) continue;
         visit[cur] = 1;
         ans += tp.first;
         int cur_x = idxx[cur], cur_y = idxy[cur];
         if (cur_x - 1 >= 0)
             pq.push(make_pair(x[cur] - candx[cur_x - 1].first, candx[cur_x - 1].second));
         if (cur_y - 1 >= 0)
             pq.push(make_pair(y[cur] - candy[cur_y - 1].first, candy[cur_y - 1].second));
         if (cur_x + 1 < N)
             pq.push(make_pair(candx[cur_x + 1].first - x[cur], candx[cur_x + 1].second));
         if (cur_y + 1 < N)
             pq.push(make_pair(candy[cur_y + 1].first - y[cur], candy[cur_y + 1].second));
    }
    printf("%lld\n", ans);
    return 0;
}
