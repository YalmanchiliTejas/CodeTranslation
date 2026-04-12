#include<bits/stdc++.h>
#include<string>

using namespace std;
#define fordebug int hoge;cin>>hoge;
#define DEKAI 1000000007
#define INF (1<<28)
#define int long long
#define lp(i,n) for(int i=0;i<n;i++)
#define lps(i,j,n) for(int i=j;i<n;i++)

signed main(){
	int n;
	cin>>n;
	int a[100000],b[100000];
	lp(i,n){
		cin>>a[i];
		b[i]=a[i];
	}
	sort(a,a+n);
	int x=a[0],y=a[0];
	int itf=1,ite=n-1;
	int ans=0;
	while(1){
		ans+=a[ite]-x;
		x=a[ite];
		ite--;
		//cout<<ans<<endl;
		if(ite<itf) break;
		ans+=a[ite]-y;
		y=a[ite];
		ite--;
		//cout<<ans<<endl;
		if(ite<itf) break;
		ans+=x-a[itf];
		x=a[itf];
		itf++;
		//cout<<ans<<endl;
		if(ite<itf) break;
		ans+=y-a[itf];
		y=a[itf];
		itf++;
		//cout<<ans<<endl;
		if(ite<itf) break;
	}
	sort(b,b+n);
	reverse(b,b+n);
	x=b[0],y=b[0];
	itf=1,ite=n-1;
	int ans2=0;
	while(1){
		ans2+=x-b[ite];
		x=b[ite];
		ite--;
		//cout<<ans2<<endl;
		if(ite<itf) break;
		ans2+=y-b[ite];
		y=b[ite];
		ite--;
		//cout<<ans2<<endl;
		if(ite<itf) break;
		ans2+=b[itf]-x;
		x=b[itf];
		itf++;
		//cout<<ans2<<endl;
		if(ite<itf) break;
		ans2+=b[itf]-y;
		y=b[itf];
		itf++;
		//cout<<ans2<<endl;
		if(ite<itf) break;
	}
	cout<<max(ans2,ans)<<endl;
	return 0;
}