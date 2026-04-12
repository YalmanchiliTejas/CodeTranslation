#include <bits/stdc++.h>
#define maxn 6086

using namespace std;

int n;
int a[maxn];
int f[maxn][maxn];
int val, sum;

struct Node{
	int x, y, z;
};

vector<Node> v;

inline void Max(int &x, int y){
	x = max(x, y);
}

int main(){
	//freopen("in.txt", "r", stdin);
	scanf("%d", &n);
	for(int i = 1;i <= 3 * n;i++) scanf("%d", &a[i]);
	if(n == 1) return printf("%d", a[1] == a[2] && a[2] == a[3]), 0;
	memset(f, -0x3f, sizeof(f));
	f[min(a[1], a[2])][max(a[1], a[2])] = val = 0;
	f[0][a[1]] = f[0][a[2]] = 0;
	f[0][0] = 0;
	for(int i = 3;i < 3 * n;i += 3){
		if(a[i] == a[i + 1] && a[i + 1] == a[i + 2]){
			sum++;
			continue;
		}
		v.push_back((Node){a[i], a[i + 1], val});
		v.push_back((Node){a[i], a[i + 2], val});
		v.push_back((Node){a[i + 1], a[i + 2], val});
		v.push_back((Node){a[i], a[i + 1], f[a[i + 2]][a[i + 2]] + 1});
		v.push_back((Node){a[i], a[i + 2], f[a[i + 1]][a[i + 1]] + 1});
		v.push_back((Node){a[i + 1], a[i + 2], f[a[i]][a[i]] + 1});
		v.push_back((Node){a[i], 0, f[a[i + 2]][a[i + 2]] + 1});
		v.push_back((Node){a[i], 0, f[a[i + 1]][a[i + 1]] + 1});
		v.push_back((Node){a[i + 1], 0, f[a[i]][a[i]] + 1});
		v.push_back((Node){0, a[i + 1], f[a[i + 2]][a[i + 2]] + 1});
		v.push_back((Node){0, a[i + 2], f[a[i + 1]][a[i + 1]] + 1});
		v.push_back((Node){0, a[i + 2], f[a[i]][a[i]] + 1});
		if(a[i] == a[i + 1]){
			for(int j = 0;j <= n;j++){
				v.push_back((Node){j, a[i + 2], f[min(a[i], j)][max(a[i], j)] + 1});
				v.push_back((Node){j, 0, f[min(a[i], j)][max(a[i], j)] + 1});
			}
		}
		if(a[i + 1] == a[i + 2]){
			for(int j = 0;j <= n;j++){
				v.push_back((Node){j, a[i], f[min(a[i + 1], j)][max(a[i + 1], j)] + 1});
				v.push_back((Node){j, 0, f[min(a[i + 1], j)][max(a[i + 1], j)] + 1});
			}
		}
		if(a[i] == a[i + 2]){
			for(int j = 0;j <= n;j++){
				v.push_back((Node){j, a[i + 1], f[min(a[i], j)][max(a[i], j)] + 1});
				v.push_back((Node){j, 0, f[min(a[i], j)][max(a[i], j)] + 1});
			}
		}
		for(int j = 1;j <= n;j++){
			v.push_back((Node){a[i], j, f[0][j]});
			v.push_back((Node){a[i + 1], j, f[0][j]});
			v.push_back((Node){a[i + 2], j, f[0][j]});
		}
		v.push_back((Node){0, a[i], val});
		v.push_back((Node){0, a[i + 1], val});
		v.push_back((Node){0, a[i + 2], val});
		while(!v.empty()){
			Node b = v.back();v.pop_back();
			int x = min(b.x, b.y), y = max(b.x, b.y), z = b.z;
			Max(f[x][y], z), Max(val, z);
		}
		/*for(int i = 0;i <= n;i++){
			for(int j = i;j <= n;j++){
				printf("%d %d %d--\n", i, j, f[i][j]);
			}
		}*/
	}
	int ans = 0;
	for(int i = 0;i <= n;i++){
		for(int j = i;j <= n;j++){
			ans = max(ans, f[i][j] + (i == a[3 * n] && j == a[3 * n]));
		}
	}
	printf("%d", ans + sum);
}