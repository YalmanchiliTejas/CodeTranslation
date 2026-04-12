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

const int N = 200005;

int n;
int a[N];
int b[N];

int main(){
	n=get();
	fo(i,1,n)a[i]=b[i]=get();
	sort(b+1,b+1+n);
	int v1=b[n/2],v2=b[n/2+1];
	fo(i,1,n){
		if (a[i]<=v1)printf("%d\n",v2);
		else printf("%d\n",v1);
	}
	return 0;
}