#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<math.h>
#include<iomanip>
#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define REVERSE(v,n) reverse(v,v+n);
#define llong long long
#define pb(a) push_back(a)
#define INF 9999999

using namespace std;

typedef pair<int,int> P;

int dy[4]={0,0,1,-1};
int dx[4]={1,-1,0,0};

int main(){
	long a,b,c,x,y;
	cin>>a>>b>>c>>x>>y;
	long ans=0,ans2=0;
	if(c*2<=a+b){
		if(x<y){
			ans+=c*2*x;
			ans+=b*(y-x);
			ans2=c*2*y;
		}
		else{
			ans+=c*2*y;
			ans+=a*(x-y);
			ans2=c*2*x;
		}
		cout<<min(ans,ans2);
		return 0;
	}
	else{
		ans=a*x+b*y;
	}
	cout<<ans;
}
