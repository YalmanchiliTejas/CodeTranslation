#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
int n,x;
int main(){
    n=read();
    int tt=0;
    int ans=0;
    for(int i=1;i<=n;i++){
    	x=read();
    	if(x>=tt) ans++;
    	tt=max(tt,x);
	}
	printf("%d",ans);
	
	return 0;
}