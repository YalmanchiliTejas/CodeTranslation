#include <bits/stdc++.h>
using namespace std;

int n;
int h[16], w[16];
int c[16];

int main()
{
	int cv[256];
	for (int i = 0; i < 3; i++){
		cv["RGB"[i]] = i + 1;
	}

	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> h[i] >> w[i];
	}
	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 4; j++){
			char d;
			cin >> d;
			c[i * 4 + j] = cv[d];
		}
	}
	
	vector<pair<int, int>> v;
	for (int i = 0; i < n; i++){
		for (int col = 1; col <= 3; col++){
			for (int bx = -3; bx < 4; bx++){
				for (int by = -3; by < 4; by++){
					int mask = (1 << 16) - 1, bit = 0;
					for (int x = bx; x < bx + h[i]; x++){
						for (int y = by; y < by + w[i]; y++){
							if (x < 0 || x >= 4 || y < 0 || y >= 4) continue;
							mask &= ~(1 << (x * 4 + y));
							bit |= (int(c[x * 4 + y] == col)) << (x * 4 + y);
						}
					}
					v.emplace_back(mask, bit);
				}
			}
		}
	}
	sort(begin(v), end(v));
	v.erase(unique(begin(v), end(v)), end(v));
	
	vector<int> dist(1 << 16, -1);
	queue<int> q;
	dist[0] = 0;
	q.push(0);
	while (q.size()){
		int cur = q.front(); q.pop();
		for (int i = 0; i < v.size(); i++){
			int x = (cur & v[i].first) | v[i].second;
			if (dist[x] == -1){
				dist[x] = dist[cur] + 1;
				q.push(x);
			}
		}
	}

	cout << dist[(1 << 16) - 1] << endl;
}