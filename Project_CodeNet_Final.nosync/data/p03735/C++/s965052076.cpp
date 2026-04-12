#include <bits/stdc++.h>
#define FI first
#define SE second
#define PB push_back
#define ll long long
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define ROF(i,a,b) for(int i=b-1;i>=a;i--)
#define YES(i) cout<<(i?"YES":"NO")<<endl
#define Yes(i) cout<<(i?"Yes":"No")<<endl
#define co(i) cout<<(i)<<endl
#define fcout cout<<fixed<<setprecision(10)
#define uni(i) i.erase(unique(i.begin(), i.end()), i.end());
#define all(i) i.begin(),i.end()
#define pint pair<int, int>
#define vint vector<int>
using namespace std;

const int INF=1e9+7;
const ll LINF=1e18;
const int MOD=1e9+7;
//const int MOD=998244353;

int n;
int x[200001],y[200001];
int main(){
	cin>>n;
	FOR(i,0,n){
		cin>>x[i]>>y[i];
		if(x[i]<y[i]) swap(x[i],y[i]);
	}
	ll ans=0;
	int rmax=0,bmax=0,rmin=INF,bmin=INF;
	FOR(i,0,n){
		rmax=max(rmax,x[i]);
		rmin=min(rmin,x[i]);
		bmax=max(bmax,y[i]);
		bmin=min(bmin,y[i]);
	}
	ans=(ll)(rmax-rmin)*(bmax-bmin);
	vector<pint> v;
	FOR(i,0,n){
		v.push_back(pint(x[i],i));
		v.push_back(pint(y[i],i));
	}
	sort(all(v));
	int st=1,en;
	int used[200001]={},unum=0;
	FOR(i,1,2*n-1){
		pint p=v[i];
		if(used[p.second]==0){
			unum++;
		}
		used[p.second]++;
		en=i;
		if(unum==n) break;
	}
	int ans2=INF;
	while(en<2*n-1){
		ans2=min(ans2,v[en].first-v[st].first);
		if(used[v[st].second]>1){
			used[v[st].second]--;
			st++;
		}else{
			en++;
			used[v[en].second]++;
		}
	}
	ll ans2l=(ll)ans2*(rmax-bmin);
	co(min(ans,ans2l));
}
