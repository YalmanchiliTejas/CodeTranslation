#include "bits/stdc++.h"

#pragma warning(disable:4996)
using namespace std;

struct aa {
	pair<int,int> prev_place;
	int prev_char;
	pair<int,int>now_place;
};
int memo[5001][5001];
int main() {
	int N;cin>>N;
	vector<int>v(N);
	for(int i=0;i<N;++i)cin>>v[i];
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
	N=v.size();
	for (int i = 0; i < N; ++i) {
		for (int j = i + 1; j < N; ++j) {
			memo[i][j]=2;
		}
	}
	int ans=0;
	for (int i = 0; i < N; ++i) {
		for (int j = 1; j < N; ++j) {
			ans=max(ans,memo[i][j]);
			int sa=v[j]-v[i];
			long long int x=v[j]*2-v[i];
			if(x>(1e9)+5)continue;
			else {
				int nx=x;
				auto it=lower_bound(v.begin()+j,v.end(),nx);
				if (it != v.end() && *it == nx) {
					memo[j][it-v.begin()]=max(memo[j][it-v.begin()],memo[i][j]+1);
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
