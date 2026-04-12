#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long int llint;
vector <pair<pair<int,int>,llint> > v;
vector <llint> v1[200005];
vector <pair<llint,int> > v2[200005];
llint t[600005],p[600005],dp[200005],maxi,off=1,x1;
void send(int x) {
	if(p[x]==0) return;
	if(t[x]==-1e17) t[x]=p[x];
	else t[x]+=p[x];
	if(x<off) {
		p[x*2]+=p[x];
		p[x*2+1]+=p[x];
	}
	p[x]=0;
}
void update(int x,int lo,int hi,int l,int r,llint v) {
	send(x);
	if(lo>r or hi<l) return;
	if(lo>=l && hi<=r) {
		p[x]+=v;
		send(x);
		return;
	}
	update(x*2,lo,(lo+hi)/2,l,r,v);
	update(x*2+1,(lo+hi)/2+1,hi,l,r,v);
	if(x<off) t[x]=max(t[x*2],t[x*2+1]);
}
llint query(int x,int lo,int hi,int l,int r) {
	send(x);
	if(lo>r or hi<l) return -1e17;
	if(lo>=l && hi<=r) return t[x];
	return max(query(x*2,lo,(lo+hi)/2,l,r),query(x*2+1,(lo+hi)/2+1,hi,l,r));
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin >> n >> m;
	while(off<n) off*=2;
	for(int i=1;i<off+n;i++) {
		t[i]=-1e17;
		//p[i]=-1e17;
	}
	for(int i=0;i<m;i++) {
		llint a,b,c;
		cin >> a >> b >> c;
		v.push_back(make_pair(make_pair(a-1,b-1),c));
		v1[a-1].push_back(c);
		v2[b].push_back(make_pair(-c,a-1));
	}
	for(int i=0;i<n;i++) {
		for(int j=0;j<v1[i].size();j++) {
			x1+=v1[i][j];
			if(i) update(1,0,off-1,0,i-1,v1[i][j]);
		}
		for(int j=0;j<v2[i].size();j++) {
			x1+=v2[i][j].first;
			if(v2[i][j].second) update(1,0,off-1,0,v2[i][j].second-1,v2[i][j].first);
		}
		dp[i]=x1;
		if(i) dp[i]=max(dp[i],query(1,0,off-1,0,i-1));
		maxi=max(maxi,dp[i]);
		/*cout << dp[i] << "\n";
		for(int j=0;j<i;j++) {
			cout << query(1,0,off-1,j,j) << " ";
		}
		cout << "\n";
		cout << query(1,0,off-1,0,0) << "\n";*/
		update(1,0,off-1,i,i,dp[i]);
		//cout << dp[i] << " " << query(1,0,off-1,0,0) << "\n";
	}
	cout << maxi;
	return 0;
}
