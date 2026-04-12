#include <bits/stdc++.h>
#define rep(i,n) for (ll i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using ull = long long unsigned;
using P = pair<int,int>;
const int INF=1001001001;
const int NMAX=8;
const int MOD=1000000007;
const int dbase=80*160;


int main(){
	int a,b,c,x,y;
	int ans=0;
	cin>>a>>b>>c>>x>>y;
	if (2*c>=a+b){
		ans=a*x+b*y;
		cout<<ans;
		return 0;
	}
	if (x<y){
		ans+=x*c*2;
	//	cout<<ans<<endl;
		y-=x;
		ans+=min(b,2*c)*y;
	//	cout<<ans<<endl;
	}
	else if (x>=y){
		ans+=y*c*2;
		x-=y;
		ans+=min(a,2*c)*x;
	}
	cout<<ans;

}
