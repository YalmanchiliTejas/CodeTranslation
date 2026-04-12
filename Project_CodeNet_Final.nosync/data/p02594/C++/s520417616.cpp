#include<bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long int
#define pb push_back
#define mp make_pair
#define in auto&it
#define out auto it 
#define rep(i,si,n) for(int i=si;i<n;++i)
int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
		//freopen("error.txt","w",stderr);
	#endif
	fastio
	int n;
	cin>>n;
	if(n>=30) cout<<"Yes";
	else cout<<"No";
	//cerr<<"time:  "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<'\n';
	return 0;
}
