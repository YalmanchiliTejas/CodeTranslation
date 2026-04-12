#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <set>
#include <unordered_map>
#include <list>
#include <unordered_set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
#define INFI 987654321
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
struct Node{
    int idx, x, y;
    Node(){};
    Node(int a, int b, int c)
    {
        idx = a;
        x= b;
        y = c;
    }
};
Node points[100001];
vector<pi> G[100001];
priority_queue<pi, vector<pi>, greater<pi>> pq;
bool visit[100001];
int N;
int main() {
    ios_base::sync_with_stdio(false);
    cin >> N;
    for(int i = 1; i <= N; ++i) {
        cin >> points[i].x >> points[i].y;
        points[i].idx = i;
    }
    sort(points + 1, points + N + 1, [](Node a, Node b) {
        return a.x < b.x;
    });
    for(int i = 2; i <= N; ++i)
    {
        int dist = points[i].x - points[i - 1].x;
        G[points[i].idx].push_back(pi(dist, points[i - 1].idx));
        G[points[i - 1].idx].push_back(pi(dist, points[i].idx));
    }
    sort(points + 1, points + N + 1, [](Node a, Node b) {
       return a.y < b.y;
    });
    for(int i = 2; i <= N; ++i)
    {
        int dist = points[i].y - points[i - 1].y;
        G[points[i].idx].push_back(pi(dist, points[i - 1].idx));
        G[points[i - 1].idx].push_back(pi(dist, points[i].idx));
    }
    pq.push(pi(0, 1));
    int ans = 0;
    while(pq.empty() == false)
    {
        pi ege = pq.top();
        pq.pop();
        int here = ege.second;
        int cost = ege.first;
        if(visit[here])
            continue;
        ans += cost;
        visit[here] = 1;
        for(pi there : G[here]) {
            if(!visit[there.second])
                pq.push(there);
        }
    }
    cout << ans;
    return 0;
}