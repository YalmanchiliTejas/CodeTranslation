#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<set>
#include<stack>
#define inf 0x3f3f3f3f
#define esp 1e-13
#include <time.h>
using namespace std;
long long read(){
    long long x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}


long long n,k,m;
long long num[100];
long long lat[100];

int main(){
	n=read();
	for (int i=1;i<=n;i++){
		num[i]=read();
	}
	k=0;
	for (int i=1;;i++){
		long long tmp=0;
		for (int i=1;i<=n;i++){
			tmp+=num[i]/n;
			lat[i]=num[i]/n;
			num[i]%=n;
		}
		for (int i=1;i<=n;i++){
			num[i]+=tmp-lat[i];
		}
		k+=tmp;
		if (tmp==0)	break;
	}
	cout<<k<<endl;
	return 0;
}