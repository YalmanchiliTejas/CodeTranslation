#include <bits/stdc++.h>

using namespace std;

#define REP(i,n)	for(int i=0, i##_len=(n); i<i##_len; ++i)
#define REPS(i,s,n)	for(int i=(s), i##_len=(n); i<i##_len; ++i)

#define ALL(obj)	(obj).begin(),(obj).end()

typedef unsigned int 			uint;
typedef unsigned long long int	ull;
typedef long long int 			ll;

typedef pair<int,int>			P;

#define LINF		((ll)1 << 63 -1)
#define INF 		2000000007
#define MINF		-2000000007
#define MAX 		100005

const int MOD = 1e9+7;
// テンプレ終了
//====================================================================//

int N;
vector<vector<int>> edge(MAX);
int used[20];

int dfs(int n,int cnt){
	if(cnt == N && used[n]==0)return 1;
	used[n] = cnt;
	int c = 0;
	for(int itr : edge[n]){
		if(used[itr]!=0)continue;
		c += dfs(itr,cnt+1);
	}
	used[n]=0;
	return c;
}

//
int main(){
	int M;cin>>N>>M;
	
	REP(i,M){
		int a,b;
		cin>>a>>b;
		edge[--a].push_back(--b);
		edge[b].push_back(a);
	}

	cout << dfs(0,1) << endl;


	return 0;
}


