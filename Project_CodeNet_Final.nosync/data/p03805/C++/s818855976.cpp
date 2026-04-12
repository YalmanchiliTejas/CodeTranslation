//#include <bits/stdc++.h>
#include "bits/stdc++.h"
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef vector<int> VI;
typedef vector<VI> VVI;//例: VVI dp(10, vector<int>(10, INF);
typedef priority_queue<int, vector<int>, less<int> > QUE_int;
const int INF = pow(10, 5) + 1;//+1しないとREになる(out of rangeになるんかな?? )

int main(void) {
	int N, M;
	cin >> N >> M;
	VVI node(N, vector<int>());
	//↑node[i][j]はノードiとつながっているノード
	//つまり存在するjの個数(node[i].size()が
	//ノードiがと繋がっているノードの個数となる

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		node[a].push_back(b);
		node[b].push_back(a);
	}

	vector<int> perm(N);//0からはじまり 2番目の数字以降は1~N-1の順列
	perm[0] = 0; //必ずノード0から開始するので最初は0
	for (int i = 1; i < N; i++) perm[i] = i;
	
	
	int ans = 0;
	do {
		//for (int i = 0; i < N; i++) cout << perm[i] << " ";
		//cout << endl;
		
		bool is_goal = true;
		for (int i = 0; i < N-1; i++) {
			int now_node = perm[i];
			int next_node = perm[i + 1];
			for (int j = 0; j < node[now_node].size(); j++) {
				if (node[now_node][j] == next_node) break;
				if (j == node[now_node].size() - 1) {
					is_goal = false; //now_nodeとnext_nodeがつながっていない
				}
			}
		}
		if (is_goal == true) ans++;
	} while (next_permutation(perm.begin()+1, perm.end()));
	//↑最初の数字は0からはじまり，　2番目以降を順列に並べる

	cout << ans << endl;
}	
