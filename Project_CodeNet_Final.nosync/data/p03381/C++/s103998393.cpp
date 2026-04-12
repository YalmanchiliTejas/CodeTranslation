#include<bits/stdc++.h>
using namespace std;
#define il inline
#define outy printf("Yes\n")
#define outn printf("No\n")
#define outf printf("First\n")
#define outs printf("Second\n")
#define FOR(a,b,c) for(int a=b;a<=c;a++)
#define FORD(a,b,c) for(int a=b;a>=c;a--)
#define FORL(a,b) for(int a=head[b];a;a=nxt[a])
#define in(a)  a=read()
#define in2(a,b)  in(a),in(b)
#define in3(a,b,c)  in2(a,b),in(c)
#define in4(a,b,c,d)  in2(a,b),in2(c,d)
#define out(a) printf("%d\n",a)
#define out2(a,b) printf("%d %d\n",a,b)
#define out3(a,b,c) printf("%d %d %d\n",a,b,c)
#define out4(a,b,c,d) printf("%d %d %d %d\n",a,b,c,d)
#define outl(a) printf("%lld\n",a)
#define outl2(a,b) printf("%lld %lld\n",a,b)
#define outl3(a,b,c) printf("%lld %lld %lld\n",a,b,c)
#define outl4(a,b,c,d) printf("%lld %lld %lld %lld\n",a,b,c,d)
#define clr(x,y) memset(x,y,sizeof(x))
il long long read(){
    char c;long long s=0,t=1;
    while(!isdigit(c=getchar()))if(c=='-')t=-1;
    do{s=s*10+c-'0';}while(isdigit(c=getchar()));
    return s*t;
}
/*------------------------------------------------------------*/
#define mod 1000000007
#define maxn 200010
#define inf 0x7fffffff
#define ll long long
/*------------------------------------------------------------*/
struct node{int v,id;}a[maxn];
bool cmp1(node a,node b){return a.v<b.v;}
int ans[maxn];
int main(){
	int n;
	in(n);
	FOR(i,1,n)in(a[i].v),a[i].id=i;
	sort(a+1,a+n+1,cmp1);
	FOR(i,1,n){
		if(i<=(n-1)/2+1)ans[a[i].id]=a[(n-1)/2+2].v;
		 else ans[a[i].id]=a[(n-1)/2+1].v;
	}
	FOR(i,1,n)out(ans[i]);
}
