#include <bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<n;i++)
#define repb(i,a,b) for(int i=a;i>=b;i--)
#define all(a) a.begin(),a.end()
#define o(a) cout<<a<<endl
#define int long long
#define fi first
#define se second
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;

signed main(){
	int n;
	while(cin>>n && n!=0){
		vector<pii> d(n+1);
		int num;
		rep(i,1,n+1){
			cin>>num;
			d[i].fi=num;
		}
		d[0].fi=-1;
		d[0].se=0;
		d[1].se=1;

		rep(i,2,n+1){
			if(!(i%2)){
				if(d[i].fi==d[i-1].fi) d[i].se=d[i-1].se+1;
				else{
					d[i].se=d[i-1].se+d[i-1-d[i-1].se].se+1;
				}
			}else{
				if(d[i].fi==d[i-1].fi) d[i].se=d[i-1].se+1;
				else d[i].se=1;
			}
		}

		int ans=0;
		int i=n;
		while(i>0){
			if(d[i].fi==0) ans+=d[i].se;
			i-=d[i].se;
		}
		o(ans);
	}
}