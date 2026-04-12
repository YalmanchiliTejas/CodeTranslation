#include<bits/stdc++.h>

using namespace std;

//#define double long double

typedef pair<int,int> ii;
typedef pair<int,long long> il;
typedef pair<long long,long long> ll;
typedef pair<ll,int> lli;
typedef pair<long long,int> li;
typedef pair<double,double> dd;
typedef pair<ii,int> iii;
typedef pair<double,int> di;
typedef pair<int,ii> iii2;
typedef pair<ii,ii> iiii;
long long mod = 1000000007LL;
long long large = 2000000000000000000LL;

vector<long long> addv,maxi;

int ul,ur;
long long uv;

void update(int o,int l,int r){
	if(ul<=l&&ur>=r){
		addv[o]+=uv;
		maxi[o]+=uv;
	}else{
		int m = (l+r)/2;
		if(ul<=m) update(o*2,l,m);
		if(ur>m) update(o*2+1,m+1,r);
		maxi[o] = max(maxi[o*2],maxi[o*2+1]);
		maxi[o]+=addv[o];
	}
}


int ql,qr;
long long qv;
void query(int o,int l,int r,long long add){
	if(ql<=l&&qr>=r){
		qv = max(qv,maxi[o]+add);
	}else{
		int m = (l+r)/2;
		if(ql<=m) query(o*2,l,m,add+addv[o]);
		if(qr>m) query(o*2+1,m+1,r,add+addv[o]);
	}
}

int main(){

	int n,m;
	cin>>n>>m;
	vector<int> l,r;
	vector<long long> a(m,0);
	l.assign(m,0);
	r  = l;
	vector<vector<int> > adj(n+1,vector<int>());
	for(int i=0;i<m;i++){
		scanf("%d%d%lld",&l[i],&r[i],&a[i]);
		a[i] = -a[i];
		l[i]--;
		adj[r[i]].push_back(i);
	}

	maxi.assign(4*n+10,0);
	addv = maxi;

	for(int i=1;i<=n;i++){

		qv = -large;
		ql = 0;
		qr = i-1;
		query(1,0,n,0);
		ul = ur = i;
		uv = qv;
		update(1,0,n);
		for(int j=0;j<(int)adj[i].size();j++){
			int id = adj[i][j];
			ur = l[id];
			ul = 0;
			uv = a[id];
			update(1,0,n);
		}
	}

	long long ans = 0;
	for(int i=0;i<m;i++) ans+=a[i];
	ans-=maxi[1];
	cout<<-ans<<endl;









	return 0;
}
