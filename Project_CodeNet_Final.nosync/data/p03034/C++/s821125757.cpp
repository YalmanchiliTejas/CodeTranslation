#include<stdio.h>
#include<map>
using namespace std;
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
int n,s[110000],A,B;
long long ans,sum;
map<int,bool> vis;
int main(){
	scanf("%d",&n);
	fo(i,0,n-1) scanf("%d",&s[i]);
	fo(C,1,n-2){
		vis.clear();
		sum=0;//!!!! 
		for(int kC=C;kC<n-1;kC+=C){
			A=n-1-kC;
			B=A-C;
			if (A<=B||B<=0) break;
			if (A==kC||vis[A]||vis[kC]) break;
			sum+=s[A]+s[kC];
			vis[A]=1;vis[kC]=1;
			if (sum>ans) ans=sum;
		}
	}
	printf("%lld\n",ans);
	return 0;
}