    #include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

struct point {
    int x, y, id;
} p[N];

bool cmp1(const point& a, const point& b) {
    if (a.x != b.x) {
        return a.x < b.x;
    }
    return a.y < b.y;
}

bool cmp2(const point& a, const point& b) {
    if (a.y != b.y) {
        return a.y < b.y;
    }
    return a.x < b.x;
}

int n;
long long weight;
bool marked[N];
vector<pair<long long, int> > adj[N];

long long prim(int x) {
    priority_queue<pair<long long, int>, vector<pair<long long, int> >, greater<pair<long long, int> > > pq;
    int y;
    long long minCost = 0;
    pair<long long, int> p;
    pq.push({0, x});
    while(!pq.empty()) {
        p = pq.top();
        pq.pop();
        x = p.second;
        if(marked[x]) {
        	continue;
		}
        minCost += p.first;
        marked[x] = true;
        for(int i = 0; i < adj[x].size(); i++) {
            y = adj[x][i].second;
            if (!marked[y]) {
            	pq.push(adj[x][i]);
            }
        }
    }
    return minCost;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> p[i].x >> p[i].y;
		p[i].id = i + 1;
	}
	sort(p, p + n, cmp1);
	for (int i = 1; i < n; i++) {
		adj[p[i].id].push_back({abs(p[i].x - p[i - 1].x), p[i - 1].id});
		adj[p[i - 1].id].push_back({abs(p[i].x - p[i - 1].x), p[i].id});
	}
	sort(p, p + n, cmp2);
	for (int i = 1; i < n; i++) {
		adj[p[i].id].push_back({abs(p[i].y - p[i - 1].y), p[i - 1].id});
		adj[p[i - 1].id].push_back({abs(p[i].y - p[i - 1].y), p[i].id});
	}
	cout << prim(1) << '\n';
	return 0;
}
