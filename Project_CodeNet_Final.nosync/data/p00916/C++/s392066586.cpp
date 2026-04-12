#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void fill(vector<vector<ll>>& grid,int i,int j,ll x)
{
	int h=grid.size(),w=grid[0].size();
	if(i<0 || h<=i || j<0 || w<=j || grid[i][j]!=x) return;
	grid[i][j]=0;
	fill(grid,i-1,j,x);
	fill(grid,i+1,j,x);
	fill(grid,i,j-1,x);
	fill(grid,i,j+1,x);
}

int main()
{
	for(int n;cin>>n && n;){
		vector<int> ls(n),ts(n),rs(n),bs(n);
		for(int i=0;i<n;i++) cin>>ls[i]>>ts[i]>>rs[i]>>bs[i];
		vector<int> xs={-1,1000001},ys={-1,1000001};
		for(int i=0;i<n;i++){
			xs.push_back(ls[i]);
			xs.push_back(rs[i]);
			ys.push_back(ts[i]);
			ys.push_back(bs[i]);
		}
		sort(begin(xs),end(xs)); xs.erase(unique(begin(xs),end(xs)),end(xs));
		sort(begin(ys),end(ys)); ys.erase(unique(begin(ys),end(ys)),end(ys));
		
		int w=xs.size(),h=ys.size();
		vector<vector<ll>> grid(h,vector<ll>(w,1ll<<n));
		for(int k=0;k<n;k++){
			int l=lower_bound(begin(xs),end(xs),ls[k])-begin(xs);
			int r=lower_bound(begin(xs),end(xs),rs[k])-begin(xs);
			int t=lower_bound(begin(ys),end(ys),ts[k])-begin(ys);
			int b=lower_bound(begin(ys),end(ys),bs[k])-begin(ys);
			for(int i=b;i<t;i++)
				for(int j=l;j<r;j++)
					grid[i][j]|=1ll<<k;
		}
		int res=0;
		for(int i=0;i<h;i++)
			for(int j=0;j<w;j++)
				if(grid[i][j]){
					fill(grid,i,j,grid[i][j]);
					res++;
				}
		cout<<res<<endl;
	}
}