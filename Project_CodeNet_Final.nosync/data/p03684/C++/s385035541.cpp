#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <queue>

using namespace std;

struct Point
{
	int x, y, i;
};

bool cmpX(Point& p1, Point& p2)
{
    return p1.x < p2.x;
}

bool cmpY(Point& p1, Point& p2)
{
	return p1.y < p2.y;
}

vector<int> visited;
vector<Point> points, points2;
vector< vector< pair<int, int> > > graph;
priority_queue< pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > pq;

int main()
{
    int N;
    cin >> N;
	points.resize(N);
	visited.assign(N, 0);
	graph.resize(N);
    for (int i = 0; i < N; ++i) {
        cin >> points[i].x >> points[i].y;
        points[i].i = i;
    }

    points2 = points;
    sort(points2.begin(), points2.end(), cmpX);
    for (int i = 1; i < points2.size(); ++i) {
		int dist = points2[i].x - points2[i-1].x;
		graph[ points2[i].i ].push_back(make_pair(dist, points2[i-1].i));
		graph[ points2[i-1].i ].push_back(make_pair(dist, points2[i].i));
    }

    points2 = points;
    sort(points2.begin(), points2.end(), cmpY);
    for (int i = 1; i < points2.size(); ++i) {
		int dist = points2[i].y - points2[i-1].y;
		graph[ points2[i].i ].push_back(make_pair(dist, points2[i-1].i));
		graph[ points2[i-1].i ].push_back(make_pair(dist, points2[i].i));
    }

    long long ans = 0;
    pq.push(make_pair(0, 0));
    while (!pq.empty()) {
        pair<int, int> edge = pq.top();
//        cout << edge.first << ' ' << edge.second << endl;
        pq.pop();


		int u = edge.second;
		if (visited[u]) continue;
		visited[u] = 1;
        ans += edge.first;


		for (int i = 0; i < graph[u].size(); ++i) {
			pair<int, int> p = graph[u][i];
            pq.push(p);
		}
    }

    cout << ans << endl;
}
