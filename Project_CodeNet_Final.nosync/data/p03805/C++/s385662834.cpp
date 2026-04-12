#include <bits/stdc++.h>

using namespace std;

#define inf 1<<30
#define pqueue priority_queue
#define mp make_pair
#define pb push_back
#define fn fill_n
typedef long long llong;
typedef unsigned long long ullong;
typedef pair<int, int> P;

vector<int> edge[10];
int cnt = 0;
int N, M;

bool use[10] = {};
void solve(int now, int many){
	if(many == N){
		cnt++;
		return;
	}

	for(int i = 0; i < edge[now].size(); i++)
		if(use[edge[now][i]] == false){
			use[edge[now][i]]++;
			solve(edge[now][i], many+1);
			use[edge[now][i]] = false;
		}

	return;
}

int main(){
	cin >> N >> M;
	for(int i = 0; i < M; i++){
		int a,b;
		cin >> a >> b;
		edge[a].pb(b);
		edge[b].pb(a);
	}

	use[1]++;
	solve(1,1);
	cout << cnt << endl;

	return 0;
}