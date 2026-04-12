#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>

using namespace std;

int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-48,ch=getchar();}
	return x*f;
}

int main()
{
	int n=read();
	int mx=0,ans=0;
	for(int i=1;i<=n;i++){
		int x=read();
		if(x>=mx) mx=x,ans++;
	}
	printf("%d\n",ans);
	return 0;
}