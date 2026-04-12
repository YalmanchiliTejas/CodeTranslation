#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define reg register
#define rep(i,a,b) for(int i=a,i##end=b;i<=i##end;++i)
#define drep(i,a,b) for(int i=a,i##end=b;i>=i##end;--i)

char IO;
int rd(){
	int s=0,f=0;
	while(!isdigit(IO=getchar())) if(IO=='-') f=1;
	do s=(s<<1)+(s<<3)+(IO^'0');
	while(isdigit(IO=getchar()));
	return f?-s:s;
}

const int N=5e5+10;

int n;
int a[N];
int b[N];
int cnt;
int s[N];
void Add(int p,int x){
	while(p<=cnt) s[p]=max(s[p],x),p+=p&-p;
}
int Que(int p){
	int res=0;
	while(p) res=max(res,s[p]),p-=p&-p;
	return res;
}
int ans;

int main(){
	rep(i,1,n=rd()) a[i]=b[i]=rd();
	sort(b+1,b+n+1);
	cnt=unique(b+1,b+n+1)-b-1;
	drep(i,n,1){
		a[i]=lower_bound(b+1,b+cnt+1,a[i])-b;
		int res=Que(a[i])+1;
		ans=max(ans,res);
		Add(a[i],res);
	}
	printf("%d\n",ans);
}

















