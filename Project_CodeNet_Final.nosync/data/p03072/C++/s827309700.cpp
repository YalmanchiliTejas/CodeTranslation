#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<cstdlib>
using namespace std;
int read(){
	int x=0,f=1; char ch=getchar();
	while (ch<'0' || ch>'9') {if (ch=='-') f=-1; ch=getchar();}
	while (ch>='0' && ch<='9') {x=x*10+ch-'0'; ch=getchar();}
	return x*f;
}
int main(){
	int n=read();
	int a[10000];
	for (int i=1; i<=n; i++) a[i]=read();
	int mx=0,ans=0;
	for (int i=1; i<=n; i++) if (a[i]>=mx){
		ans++;
		mx=a[i];
	}
	cout<<ans<<endl;
	return 0;
}