#include<bits/stdc++.h>
#define int long long
#define register rg
#define file(a) freopen(a".in","r",stdin);freopen(a".out","w",stdout)
using namespace std;
typedef long long ll;
main() {
	//file("a");
	int maxx=0,a=0,n,ans=0;
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>a;
		maxx=max(maxx,a);
		if(a==maxx)
		ans++; 
	}
	cout<<ans;
	return 0;
}
