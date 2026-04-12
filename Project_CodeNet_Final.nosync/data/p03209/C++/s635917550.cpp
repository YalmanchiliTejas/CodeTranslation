#include <bits/stdc++.h>
#define f(i,n) for(int i=0;i<(n);i++)
#define P pair<int,int>
#define mod 1000000007
#define S second
#define F first
#define int long long
using namespace std;
pair<int,int> p[50];
bool bo[50];
signed main(){
	int a,b,ans=0,z;
	cin>>a>>b;
	z=a-1;
	p[0].F=1;
	p[0].S=1;
	f(i,49){
		p[i+1].F=p[i].F*2+3;
		p[i+1].S=p[i].S*2+1;
	}
	b--;
	JOI:;
	if(b==0) goto IOI;
	else if(b<p[z].F){
		b--;
		z--;
		goto JOI;
	}
	else{
		ans+=p[z].S;
		b-=p[z].F;
		if(b&&!bo[z]){
			ans++;
			b--;
			bo[z]=true;
		}
		else if(bo[z]) goto IOI;
		goto JOI;
	}
	IOI:;
	cout<<ans<<endl;
	return 0;
}
