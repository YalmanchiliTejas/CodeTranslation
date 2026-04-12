#include <map>
#include <queue>
#include <stack>
#include <cmath>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#define lowbit(x) (x&(-x))
#define rep(i,x,y) for(int i=x;i<=y;i++)
#define drep(i,x,y) for(int i=x;i>=y;i--)
#define repg(i,x) for(int i=p[x];i;i=e[i].nt)  
using namespace std;
typedef long long LL;
LL read(){
	LL rtn=0;char ch=getchar();
	while(ch>'9'||ch<'0')ch=getchar();
	while(ch<='9'&&ch>='0')rtn=(rtn<<3)+(rtn<<1)+ch-'0',ch=getchar();
	return rtn;
}
const int N=200010;
int a[N],n; 
int main(){
#ifdef WK
	freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
#endif
	n=read();
	rep(i,1,n)a[i]=read();
	if(n%2==0){
		for(int i=n;i;i-=2)printf("%d ",a[i]);
		for(int i=1;i<=n;i+=2)printf("%d ",a[i]);
	}else{
		for(int i=n;i>0;i-=2)printf("%d ",a[i]);
		for(int i=2;i<=n;i+=2)printf("%d ",a[i]);
	}
	return 0;
}