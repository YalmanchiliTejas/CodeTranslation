#include<bits/stdc++.h>
using namespace std;

#define IO ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define m(a,b) memset(a,b,sizeof(a))
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long ll;
typedef pair<string,int> p;
const int MAXN=1e5+10;
int a[105];
int main(){
	IO;
	int a,b,c,x,y;
	cin>>a>>b>>c>>x>>y;
	if (x==y) cout<<min(x*(a+b),2*x*c)<<endl;
	else{
		int ans=0;
		if (x>y){
			ans+=(x-y)*a;
			ans+=min(y*(a+b),2*y*c);
		}
		else{
			ans+=(y-x)*b;
			ans+=min(x*(a+b),2*x*c);
		}
		if (max(x,y)*2*c<ans) ans=y*2*c;
		cout<<ans<<endl;
	}
	return 0;
}