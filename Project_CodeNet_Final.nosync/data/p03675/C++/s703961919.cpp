#include <cstdio>
using namespace std;

const int MAXN=200005;
int n,a[MAXN],b[MAXN];

inline int read(){
	char c; int x;
	while(c=getchar(),c<'0' || '9'<c);
	x=c-'0';
	while(c=getchar(),'0'<=c && c<='9')
		x=x*10+c-'0';
	return x;
}

int main(){
	n=read();
	for(int i=1;i<=n;++i)
		a[i]=read();
	if(n%2){
		for(int i=n;i>=1;i-=2)
			printf("%d ",a[i]);
		for(int i=2;i<n;i+=2)
			printf("%d ",a[i]);
	}
	else{
		for(int i=n;i;i-=2)
			printf("%d ",a[i]);
		for(int i=1;i<n;i+=2)
			printf("%d ",a[i]);
	}
	return 0;
}