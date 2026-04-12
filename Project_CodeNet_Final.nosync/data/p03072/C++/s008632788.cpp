#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int p=0,f=1; char c=getchar();
	while(c<'0'||c>'9'){ if(c=='-') f=-1; c=getchar();}
	while(c>='0'&&c<='9'){ p=(p<<3)+(p<<1)+(c^48); c=getchar();}
	return f*p;
}
int n,h[21],maxx[21],ans;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&h[i]);
		if(maxx[i-1]<=h[i]){
			ans++;
			maxx[i]=h[i];
		}
		else maxx[i]=maxx[i-1];
	}
	printf("%d",ans);
	return 0;
}