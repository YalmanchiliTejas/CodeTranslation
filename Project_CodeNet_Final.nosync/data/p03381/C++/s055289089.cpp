#include<bits/stdc++.h>

using namespace std;

inline int read(){
	char ch=getchar();int x=0,f=1;
    while(ch<'0' || ch>'9') {
       if(ch=='-') f=-1;
	  	  ch=getchar();
	}
    while(ch<='9' && ch>='0') {
	   x=x*10+ch-'0';
	   ch=getchar();
	}
    return x*f;
}

int a[200100],b[200100];

int main(){
	int n=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
		b[i]=a[i];
	}
	sort(b+1,b+n+1);
	int l=b[n/2],r=b[n/2+1];
	for(int i=1;i<=n;i++){
		if(a[i]<=l){
			printf("%d\n",r);
		}
		else printf("%d\n",l);
	}
	return 0;
}
