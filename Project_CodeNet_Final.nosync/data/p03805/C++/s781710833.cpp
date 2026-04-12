#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

typedef struct {
	bool to[8];
} node;

node _node[8];

int n,m;
int ans = 0;

void go(int now,bool x[8],int cnt) {
	if (cnt == n - 1) {
		/*for (int i = 0;i < 8;i++) {
			if (x[i] == true) {
				cout << i << " ";
			}
		}*/
		// cout << now << " ";
		ans++;
		return;
	}
	for(int i = 0;i < 8;i++) {
		if (_node[now].to[i] == true && x[i] == false) {
			bool y[8];
			for (int j = 0;j < 8;j++) {
				y[j] = x[j];
			}
			y[i] = true;
			go(i,y,cnt+1);
		}
	}
	return;
}

int main() {
	cin >> n >> m;
	for (int i = 0;i < 8;i++) {
		for (int j = 0;j < 8;j++) {
			_node[i].to[j] = false;
		}
	}
	for (int i = 0;i < m;i++) {
		int a,b;
		cin >> a >> b;
		_node[a-1].to[b-1] = true;
		_node[b-1].to[a-1] = true;
	}
	bool start[8] = {true,false,false,false,false,false,false,false};
	go(0,start,0);
	cout << ans << endl;
}