#include<bits/stdc++.h>
#define pf printf
#define sc(x) scanf("%d",&x);
#define scs(x) scanf("%s",x);
#define scl(x) scanf("%lld",&x);
#define rep(i,s,e) for(int i=s; i<=e; ++i)
#define dep(i,s,e) for(int i=s; i>=e; --i)
typedef long long ll;
using namespace std;
ll a[200005],b[200005][2],c[200005];

int main(){
	int n;
	sc(n);
	rep(i,1,n){
		b[i][0]=b[i-1][0];
		b[i][1]=b[i-1][1];
		scl(c[i]);
		if(i%2==1)b[i][1]+=c[i];
		else b[i][0]+=c[i];
	}a[1]=0;a[2]=max(c[1],c[2]);
	rep(i,3,n){
		if(i%2==1){
			a[i]=b[i-2][1];//取i-2的；
			a[i]=max(a[i],a[i-3]+c[i-1]);//取i-1的； 
			a[i]=max(a[i],a[i-2]+c[i]);//取i的；
		}
		else {
			a[i]=b[i-1][1];//取i-1的；
			a[i]=max(a[i],a[i-2]+c[i]);//取i的； 
		}	
	}pf("%lld\n",a[n]); 
}