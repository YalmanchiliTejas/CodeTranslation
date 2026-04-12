#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#define check(s) (s<='9'&&s>='0')
using namespace std;
int n;
struct Node{
	int v,num,ans;
};
Node a[200005];
inline int read(){
	char ch;int res;
	for(ch=getchar();!check(ch);ch=getchar());
	res=ch-'0';
	for(ch=getchar();check(ch);ch=getchar())
	res=res*10+ch-'0';
	return res;
}
bool cmp(Node x,Node y){
	return x.v<y.v;
}
bool cmp2(Node x,Node y){
	return x.num<y.num;
}
int main(){
	n=read();
	for(int i=1;i<=n;i++) {
	  a[i].v=read();
	  a[i].num=i; 
	}
	int x1,x2;
	sort(a+1,a+n+1,cmp);
	x1=a[n>>1].v ;
	x2=a[(n>>1)+1].v ;
		for(int i=1;i<=(n>>1);i++)
		  a[i].ans=x2;
		for(int i=(n>>1)+1;i<=n;i++)
		  a[i].ans=x1;
	sort(a+1,a+n+1,cmp2);
	for(int i=1;i<=n;i++) printf("%d\n",a[i].ans);
   return 0;	
	
}