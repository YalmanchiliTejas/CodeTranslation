#include<bits/stdc++.h>
#define LL long long
using namespace std;
inline int read(){
	int x=0,z=1;char y=getchar();
	while(y<'0'||y>'9'){if(y=='-')z=-1;y=getchar();}
	while(y>='0'&&y<='9')x=x*10+y-'0',y=getchar();
	return x*z;
}
int main(){
    int a=read(),b=read(),c=read();
    a-=c;
    printf("%d",a/(b+c));
	return 0;
}