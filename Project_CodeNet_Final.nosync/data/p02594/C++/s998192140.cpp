#include<algorithm>
#include<stack>
#include<ctime>
#include<cstring>
#include<cmath>
#include<iostream>
#include<iomanip>
#include<cstdio>
#include<queue>
using namespace std;
inline int read(){
	int num=0,f=1;char x=getchar();
	while(x<'0'||x>'9'){if(x=='-')f=-1;x=getchar();}
	while(x>='0'&&x<='9'){num=num*10+x-'0';x=getchar();}
	return num*f;
}
int main(){
	int n=read();
	if(n>=30)puts("Yes");
	else puts("No"); 
	return 0;
}
