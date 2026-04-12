#include "bits/stdc++.h"

#pragma warning(disable:4996)
using namespace std;
using ld =long double;

int ans=0;

int N, K;
pair<int,int> dfs(const vector<vector<int>>&edges, const int now, const int from) {
	int sum=0;
	vector<int>v(2,0);
	int one_num=0;
	int ch_num=1;
	bool flag=false;
	int ch_big_num=0;
	for (auto e : edges[now]) {
		if(e==from)continue;
		else {
			auto k=dfs(edges,e,now);

			int put_reward=k.first;
			int not_reward=0;
			if (k.second >= K) {
				not_reward=1;
				if (put_reward != 0) {
					flag=true;
				}
				put_reward=1;
				ch_big_num++;
			}
			else {
				flag=true;
			}
			ch_num+=k.second;
			put_reward=max(put_reward,k.first);

			if (put_reward >= 1) {
				sum++;
				v.push_back(put_reward);

				sort(v.begin(), v.end(), greater<int>());
				if (v.size() == 3)v.pop_back();
			}
		}
	}
	
	int nans=sum;
	if(!flag)nans--;
	if(v[0]>=1)nans+=v[0]-1;
	if(v[1]>=1)nans+=v[1]-1;
	if (ch_num <= N - K) {
		ans=max(ans,nans+1);
	}
	else {
		ans=max(ans,nans);
	}
	int kans=sum;
	if(v[0]>=1)kans+=v[0]-1;
	kans=max(kans,ch_big_num);
	return make_pair(kans,ch_num);
}

int main() {cin>>N>>K;
	vector<vector<int>>edges(N);
	for (int i = 1; i < N; ++i) {
		int a,b;cin>>a>>b;a--;b--;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	dfs(edges,0,-1);
	cout<<ans<<endl;
	return 0;
}
