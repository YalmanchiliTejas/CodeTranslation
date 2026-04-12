#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0;i<n;i++)
#define REPR(i,n) for(int i=n;i>=0;i--)
#define FOR(i,m,n) for(int i=m;i<n;i++)
#define EPS (1e-7)

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;

int vx[]={0,1,0,-1};
int vy[]={1,0,-1,0};

int dx[]={1,0,-1,1,-1,1,0,-1};
int dy[]={1,1,1,0,0,-1,-1,-1};

const ll mod=1e9+7;
const int INF=INT_MAX/2;
const int MAX=1e9;

int main(){
	int x,y,z;
	cin>>x>>y>>z;
	int ans=(x-z)/(y+z);
	cout<<ans<<endl;
	return 0;
}
