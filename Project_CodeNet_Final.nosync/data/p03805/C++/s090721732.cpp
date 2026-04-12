#include<iostream>
#include<vector>

using namespace std;

int n, m;
vector<int> e[9];
int res = 0;

void dfs(int p, int sum, int v[]) { //p:現在訪問しているノード番号 sum:今までに訪れたノードの数 v:今までに訪れたノード番号を格納する配列
	int tempv[9];
	for (int i = 0; i < 9; i++)tempv[i] = v[i];

	/*for (int i = 1; i <= 8; i++)cout << v[i] << ' ';
	cout << endl;*/

	sum++;
	if (sum == n) {
		res++;
		//cout << "g =" << ' ' << p << endl;
		return;
	}

	//ノードpに隣接するノードを探索
	for (int i = 0; i < e[p].size(); i++) {	//もし隣接ノードが未訪問なら再帰する
		//cout << "check" << e[p][i] << endl;
		if (v[e[p][i]] == 0) {
			v[e[p][i]] = 1; //訪問するノードを記憶
			dfs(e[p][i], sum, v);
			for (int j = 0; j < 9; j++)v[j] = tempv[j];
		}
	}

	return; //隣接ノードがすべて訪問済みで条件に一致しない場合は戻る
}

int main() {

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		e[a].push_back(b);
		e[b].push_back(a);
	}

	int v[9] = { 0,1,0,0,0,0,0,0,0 };
	dfs(1, 0, v);

	cout << res << endl;

	return 0;
}