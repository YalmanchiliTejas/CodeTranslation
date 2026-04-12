#include <bits/stdc++.h>
#define f(i,n) for(int i=0;i<(n);i++)
#define P pair<int,int>
#define mod 1000000007
#define S second
#define F first
#define int long long
using namespace std;
signed main(){
	int a,b,ans=INT_MAX,sum=0;
	cin>>a;
	f(i,a){
		cin>>b;
		sum+=b;
		ans=min(ans,sum/(i+1));
	}
	cout<<ans<<endl;
	return 0;
}

