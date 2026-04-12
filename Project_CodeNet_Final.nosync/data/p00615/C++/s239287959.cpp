#include <bits/stdc++.h>
#define rep(i,l,n) for(int i=l;i<n;i++)
#define all(a) a.begin(),a.end()
#define o(a) cout<<a<<endl
#define int long long
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;

signed main(){
	int n,m;
	while(1){
		cin>>n>>m;
		if(n+m==0) break;
		vi d(n+m+1,0);
		d[0]=0;
		rep(i,1,n+m+1) cin>>d[i];
		sort(all(d));
		int MAX=0;
		rep(i,0,n+m){
			MAX=max(MAX,d[i+1]-d[i]);
		}
		o(MAX);
	}
}