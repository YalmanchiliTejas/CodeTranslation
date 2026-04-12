#include<bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;i++)
#define FORD(i,a,b) for(int i=(a),_b=b;i>=_b;i--)
#define arrayin(a,n) for(int i=0;i<n;i++) cin>>a[i];
#define arrayout(a,n) for(int i=0;i<n;i++) cout<<a[i]<<" ";cout<<"\n";
#define endl "\n"
#define MS(v) memset(v,0,sizeof(v))
#define ULL unsigned long long
#define LL unsigned long long
#define elif else if

void solve() {
	int x;
	cin>>x;
	if(x==3 || x==5 || x==7) cout<<"YES";
	else cout<<"NO";
}


int main() {
	#ifdef HoaSayyy
//		freopen("" , "r" , stdin);
		//freopen("" , "w" , stdout);
	#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	solve();
	cout<<"\n";
    return 0;
}



