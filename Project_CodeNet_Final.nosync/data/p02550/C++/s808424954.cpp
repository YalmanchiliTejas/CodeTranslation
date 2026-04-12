#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define FOR(i,a,b) for(int i=(a); i<=(b); i++)
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define chmin(a,b) if((a)>(b)) (a)=(b);
#define chmax(a,b) if((a)<(b)) (a)=(b);
#define vi vector<int>
#define pii pair<int,int>
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define pb push_back
#define pf push_front
int gcd(int a,int b){/*a>=0,b>=0,￢(a=b=0)*/
  while(min(a,b)>0){if(a<b)swap(a,b);a%=b;}return max(a,b);
}
int dx[]={1,0,-1,0,1,-1,-1,1};
int dy[]={0,1,0,-1,1,1,-1,-1};
const int MOD = 1e9+7;
const int MOD9 = 998244353;
const long long INF = 1e18+10;

/*--------------------------------------------------------------------*/
int f(int x,int m){
	return x%m;
}

signed main(){
	int n,x,m;
	cin>>n>>x>>m;
	
	vi path;

	vi visit(100000,-1);
	int ans=0;
	int now=x;
	int st=-1;
	int len=-1;
	int rest=-1;
	FOR(i,1,n){
		path.pb(now);
		if(visit[now]>-1){
			st=visit[now];
			len=i-visit[now];
			rest=n-i+1;
			
			// cout<<"st="<<st<<endl;
			// cout<<"len="<<len<<endl;
			// cout<<"rest="<<rest<<endl;
			break;
			
		}
		visit[now]=i;
		ans+=now;
		now=f(now*now,m);
	}
	// cout<<"ans1="<<ans<<endl;
	int tot=0;
	FOR(i,st,st+len-1){
		tot+=path[i];
	}
	// cout<<"tot="<<tot<<endl;

	ans+=rest/len*tot;
	// cout<<"ans2="<<ans<<endl;
	
	FOR(i,st,st+(rest%len)-1){
		ans+=path[i-1];
	}
	cout<<ans<<endl;

	// rep(i,path.size()){
	// 	cout<<' '<<path[i];
	// }
	// cout<<endl;

	return 0;
}