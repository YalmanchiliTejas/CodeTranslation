#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define int long long
#define inf 1000000007
#define LINF 100000000000000007LL
#define ll long long
using namespace std;
int ps[100],ts[100];
int calc( int lev, int pos ){
	if( pos == 0 ) return 0;
	if( lev == 0 && pos == 1 ) return 1;
	if( pos <= ts[lev-1] + 1 ){
		return calc( lev-1, pos-1 );
	}
	if( pos == ts[lev-1] + 2 ){
		return ps[lev-1] + 1;
	}
	if( pos < ts[lev] ){
		return ps[lev-1] + 1 + calc( lev-1, pos - ts[lev-1] - 2 );
	}
	if( pos == ts[lev] ){
		return ps[lev];
	}
	return -1;
}
signed main(){
	int n,x;
	cin>>n>>x;
	ps[0] = 1; ts[0]=1;
	for(int i=1;i<=50;i++){
		ps[i] = ps[i-1] * 2 + 1;
		ts[i] = ts[i-1] * 2 + 3;
	}
	int ans = calc(n,x);
	cout<<ans<<endl;
	return 0;
}