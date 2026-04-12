#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0;i<n;i++)
#define REPR(i,n) for(int i=n;i>=0;i--)
#define EPS (1e-7)

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
typedef pair<double,int> pdi;

int vx[]={0,0,-1,1};
int vy[]={1,-1,0,0};

int dx[]={1,0,-1,1,-1,1,0,-1};
int dy[]={1,1,1,0,0,-1,-1,-1};

const ll mod=1e9+7;
const int INF=INT_MAX/2;
const int MAX=1e9;
const int MAX_V=10000;

int main(){
	int n;
	cin>>n;
	int a[n];
	REP(i,n)cin>>a[i];
	vector<pii> p;
	REP(i,n)p.push_back(pii(a[i],i));
	sort(p.begin(),p.end());
	int ans[n];
	REP(i,n){
		int id=p[i].second;
		if(i<n/2)ans[id]=p[n/2].first;
		else if(i==n/2-1)ans[id]=p[n/2].first;
		else if(n==n/2)ans[id]=p[n/2-1].first;
		else ans[id]=p[n/2-1].first;
	}
	REP(i,n)cout<<ans[i]<<endl;
	return 0;
}