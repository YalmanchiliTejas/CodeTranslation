#include<cstdio>
#include<cstring>
#include<cctype>
#include<algorithm>
#define ll long long
using namespace std;
int read(){
    char c;int s=0,t=1;
    while(!isdigit(c=getchar()))if(c=='-')t=-1;
    do{s=s*10+c-'0';}while(isdigit(c=getchar()));
    return s*t;
}
/*------------------------------------------------------------*/
const int inf=0x3f3f3f3f;

int n,a[200010],b[200010];

int main(){
	n=read();
	for(int i=1;i<=n;i++)a[i]=read(),b[i]=a[i];
	sort(b+1,b+n+1);
	int x=b[n/2];
	for(int i=1;i<=n;i++){
		if(a[i]<=x)printf("%d\n",b[n/2+1]);else printf("%d\n",x);
	}
	
	
	return 0;
}