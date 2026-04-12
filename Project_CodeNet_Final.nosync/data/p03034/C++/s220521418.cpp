#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
#define gmax(x,y) x=max(x,y)
#define gmin(x,y) x=min(x,y)
#define F first
#define S second
#define P pair
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define V vector
#define RE return
#define ALL(a) a.begin(),a.end()
#define MP make_pair
#define PB emplace_back
#define PF emplace_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
using namespace std;
int a[100005],n; 
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	rep(i,0,n)cin>>a[i];
	int ans=-1e17,l,r,t;
	rep(i,1,n){
		l=0;r=n-1;t=0;
		if(r%i==0){
			while(l<r){
				t+=a[l]+a[r];
				gmax(ans,t);
				l+=i;r-=i;
			}
		}else{
			while(r>i){
				t+=a[l]+a[r];
				gmax(ans,t);
				l+=i;r-=i;
			}
		}
	}
	cout<<ans<<'\n';
	RE 0;
}


