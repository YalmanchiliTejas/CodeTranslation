#include<bits/stdc++.h>
using namespace std;
#define int long long
#define f(i,n) for(int i=0;i<n;++i)
#define pie 3.141592653589793238462643383279
#define mod 1e9+7
int x[100000],y[100000];
signed main(){
	int a,b,ans=0,ma=0;
	cin>>a;
	f(i,a){
		cin>>b;
		if(b>=ma){
			ans++;
			ma=max(ma,b);
		}
	}
	cout<<ans<<endl;
}
