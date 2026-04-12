#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<set>
#include<bitset>
#include<map>

#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

typedef long long LL;
typedef double db;

int get(){
	char ch;
	while(ch=getchar(),(ch<'0'||ch>'9')&&ch!='-');
	if (ch=='-'){
		int s=0;
		while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
		return -s;
	}
	int s=ch-'0';
	while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
	return s;
}

int main(){
	int n=get(),k=get();
	LL ans=0;
	fo(i,k+1,n){
		fo(j,0,n/i)
		if (j)ans=ans+max(0,min(n-j*i,i-1)-k+1);
		else ans=ans+max(0,min(n-j*i,i-1)-max(k,1)+1);
	}
	printf("%lld\n",ans);
	return 0;
}