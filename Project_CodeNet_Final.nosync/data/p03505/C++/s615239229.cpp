#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#define rr register
using namespace std;
inline int read(){
	int s=0,m=0;
	char ch=getchar();
	while(!isdigit(ch)){m|=ch=='-';ch=getchar();}
	while(isdigit(ch)){s=(s<<3)+(s<<1)+(ch^48);ch=getchar();}
	return m?-s:s;
}
inline int f_swap(int &a,int &b){
	int l=a;
	a=b;
	b=l;
}
long long a,b,k;
main(){
    scanf("%lld%lld%lld",&k,&a,&b);
    if(k<=a)return puts("1"),0;
    else if(a<=b)return puts("-1"),0;
    else printf("%lld\n",((k-a)/(a-b)+bool((k-a)%(a-b)))<<1|1);
}