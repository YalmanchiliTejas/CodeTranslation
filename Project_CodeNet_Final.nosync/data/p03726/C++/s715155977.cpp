#include<bits/stdc++.h>
#include<unordered_set>
#include<unordered_map>
using namespace std;

#define MAX 100002

int n;

vector<int> v[MAX];

bool ng1[MAX];
int p[MAX];

int having_must[MAX];


inline void dfs(int b,int pr=-1){
	p[b] = pr;
	int siz = 0;
	int z = 0;
	for (int i = 0; i < v[b].size(); i++){
		int go = v[b][i];
		if (go == pr)continue;
		dfs(go,b);
		siz++;
		if (v[go].size() == 1){
			z++;
		}
	}
	if (pr != -1 && v[pr].size() == 1){
		z++;
	}
	if (z > 1){
		puts("First");
		exit(0);
	}
	having_must[b] = z;
}
map<int, int> dp[MAX][2];  //0 white 1 black

int ex[MAX][2];
inline bool dfs2(int b, int pr,int flag){
	if (v[b].size() == 1){
		if (flag == true){
			return true;
		}
		return false;
	}
	if (dp[b][flag].count(pr)){
		if (flag == false){
			return dp[b][flag][pr];
		}
		else{
			return dp[b][flag][pr] == v[b].size() - 1;
		}
	}
	if (dp[b][flag].size() == 0){
		ex[b][flag] = pr;
		dp[b][flag][pr] = 0;
		for (int i = 0; i < v[b].size(); i++){
			if (v[b][i] == pr)continue;
			int go = v[b][i];
			int nex = dfs2(go, b, flag ^ true);
			dp[b][flag][pr] += nex;
		}
	}
	else{
		dp[b][flag][pr] = dp[b][flag][ex[b][flag]] - dfs2(pr, b, flag ^ true) + dfs2(ex[b][flag], b, flag ^ true);
	}
	if (flag == false){
		return dp[b][flag][pr];
	}
	else{
		return dp[b][flag][pr] == v[b].size() - 1;
	}
}
int main(){
	cin >> n;
	if (n == 2){
		puts("Second");
		return 0;
	}
	for (int i = 1; i < n; i++){
		int a, b;
		scanf("%d%d", &a, &b);
		a--;
		b--;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dfs(0);
	for (int i = 0; i < n; i++){
		int sum = 0;
		for (int j = 0; j < v[i].size(); j++){
			int go = v[i][j];
			if (dfs2(go, i, false)){
				sum++;
			}
		}
		if (sum == v[i].size()){
			puts("First");
			return 0;
		}
	}
	puts("Second");
	return 0;
}