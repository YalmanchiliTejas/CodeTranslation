#include<bits/stdc++.h>
#define FO(x) {freopen(#x".in","r",stdin);\
				freopen(#x".out","w",stdout);}
#define fir first
#define sec second
using namespace std;
typedef long long ll;
template<typename T>inline bool cmin(T &a,const T &b){ return a>b?a=b,1:0;}
template<typename T>inline bool cmax(T &a,const T &b){ return a<b?a=b,1:0;}
int a[201234];
int main(){
	int i,n,f=0;scanf("%d",&n);
	for(i=1;i<=n;i++)scanf("%d",a+i);
	for(i=n;i>0;i-=2)
		printf("%d ",a[i]);
	for(i=(n&1?2:1);i<=n;i+=2){
		printf("%d ",a[i]);
	}
	return 0;
}
