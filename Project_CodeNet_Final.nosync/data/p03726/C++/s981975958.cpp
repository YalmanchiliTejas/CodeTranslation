#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for(int i = (int) (l);i < (int) (r);i++)
#define ALL(x) x.begin(),x.end()
template<typename T> bool chmax(T& a,const T& b){ return a < b ? (a = b,true) : false; }
template<typename T> bool chmin(T& a,const T& b){ return b < a ? (a = b,true) : false; }
typedef long long ll;

int N;
vector<int> edge [100001];
int dp [100001],dp2 [100001],par [100001];

void dfs(int curr,int prev)
{
	dp [curr] = 0;
	for(const auto& it : edge [curr]) if(it != prev){
		dfs(it,curr);
		par [it] = curr;
		if(dp [it] == 0){
			dp [curr] = 1;
		}
	}
}

void dfs2(int curr,int prev,int val)
{
	dp2 [curr] = val;
	int sum = 0;
	if(prev != -1){
		sum += dp2 [curr] == 0;
	}
	for(const auto& it : edge [curr]) if(it != prev){
		sum += dp [it] == 0;
	}
	for(const auto& it : edge [curr]) if(it != prev){
		if(sum - (dp [it] == 0) > 0){
			dfs2(it,curr,1);
		}
		else{
			dfs2(it,curr,0);
		}
	}
}

int main()
{
	scanf("%d",&N);
	FOR(i,0,N - 1){
		int u,v;
		scanf("%d%d",&u,&v);
		edge [u].push_back(v);
		edge [v].push_back(u);
	}

	dfs(1,-1);
	dfs2(1,-1,1);

	bool ans = false;
	FOR(i,1,N + 1){
		bool b = true;
		for(const auto& it : edge [i]) if(it != par [i]){
			b &= dp [it];
		}
		b &= dp2 [i];
		ans |= b;
	}
	printf("%s\n",ans ? "First" : "Second");

	return 0;
}
