#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int H, W; cin >> H >> W;
	char c[105][105];

	bool a[105], b[105];
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));

	for (int i = 0;i < H;i++){
		bool flag = true;
		for (int j = 0;j < W;j++){
			cin >> c[i][j];
			if(c[i][j] != '.') flag = false;
		}
		if(flag) a[i] = true;
	}

	for (int j = 0;j < W;j++){
		bool flag = true;
		for (int i = 0;i < H;i++){
			if(c[i][j] != '.') flag = false;
		}
		if(flag) b[j] = true;
	}

	for (int i = 0;i < H;i++){
		for (int j = 0;j < W;j++){
			if(a[i] || b[j]) continue;
			cout << c[i][j];
		}
		if(!a[i])cout << endl;
	}

	return 0;

}
