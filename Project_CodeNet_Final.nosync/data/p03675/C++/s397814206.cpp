#include <bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0;char ch=getchar();
	while (!isdigit(ch)) ch=getchar();
	while (isdigit(ch)) x=x*10+ch-'0',ch=getchar();
	return x;
}
int a[200005],n,b[200005];
int main(){
	n=read();
	for (int i=1;i<=n;++i) a[i]=read();
	int cur=1;bool flag=1;
	for (int i=n;i;--i){
		b[cur]=a[i];
		if (flag) cur=n-cur+1;
		else cur=n-cur+2;
		flag^=1;
	}
	for (int i=1;i<=n;++i) printf ("%d ",b[i]);
	return 0;
}
