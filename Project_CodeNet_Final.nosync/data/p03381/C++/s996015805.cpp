#include<bits/stdc++.h>
#define REP(i,a,b) for(int i=(a);i<=(b);++i)
#define DEC(i,a,b) for(int i=(a);i>=(b);--i)
#define DEBUG(x) cerr<<#x" == "<<x<<endl
using namespace std;
typedef long long ll;
inline int read(){
	int w=0,p=0;char c;
	while(!isdigit(c=getchar()))if(c=='-')p=1;
	while(isdigit(c))w=(w<<1)+(w<<3)+(c^'0'),c=getchar();
	return p?-w:w;
}
int n,a[200007],p[200007],t[200007];
inline bool cmp(int i,int j){return a[i]<a[j];}
int main(){
	n=read();
	REP(i,1,n)a[i]=read(),p[i]=i;
	sort(p+1,p+1+n,cmp);
	REP(i,1,n)t[p[i]]=i;
	REP(i,1,n)printf("%d\n",a[p[t[i]<=n/2?n/2+1:n/2]]);
	return 0;
}
