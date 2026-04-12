#include<iostream>
#include<vector>
#define int long long
using namespace std;
const int N=2e5+2;
const int inf=1e18+2;
int it[4*N],dp[N],lazy[4*N];
vector<pair<int,int> > que[N];
void upd(int idx,int l,int r,int lef,int rig,int val){
	if(lef>r||rig<l){
		return;
	}
	if(l>=lef&&r<=rig){
		it[idx]+=val;
		lazy[idx]+=val;
		return;
	}
	if(lazy[idx]){
		it[2*idx]+=lazy[idx];
		it[2*idx+1]+=lazy[idx];
		lazy[2*idx]+=lazy[idx];
		lazy[2*idx+1]+=lazy[idx];
		lazy[idx]=0;
	}
	upd(2*idx,l,(l+r)/2,lef,rig,val);
	upd(2*idx+1,(l+r)/2+1,r,lef,rig,val);
	it[idx]=max(it[2*idx],it[2*idx+1]);
}
int getmax(int idx,int l,int r,int lef,int rig){
	if(l>rig||r<lef){
		return -inf;
	}
	if(l>=lef&&r<=rig){
		return it[idx];
	}
	if(lazy[idx]){
		it[2*idx]+=lazy[idx];
		it[2*idx+1]+=lazy[idx];
		lazy[2*idx]+=lazy[idx];
		lazy[2*idx+1]+=lazy[idx];
		lazy[idx]=0;
	}
	return max(getmax(2*idx,l,(l+r)/2,lef,rig),getmax(2*idx+1,(l+r)/2+1,r,lef,rig));
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m,i,j,k,l,ans=0;
	cin>>n>>m;
	for(i=1;i<=m;i++){
		cin>>j>>k>>l;
		que[j+1].push_back({j+1,l});
		que[k+2].push_back({j+1,l});
	}
	for(i=2;i<=n+1;i++){
		for(j=0;j<que[i].size();j++){
			if(que[i][j].first==i){
				upd(1,1,n+1,1,que[i][j].first-1,que[i][j].second);
			}
			else{
				upd(1,1,n+1,1,que[i][j].first-1,-que[i][j].second);
			}
		}
		dp[i]=getmax(1,1,n+1,1,i-1);
		upd(1,1,n+1,i,i,dp[i]);
		ans=max(ans,dp[i]);
	}
	cout<<ans;
}