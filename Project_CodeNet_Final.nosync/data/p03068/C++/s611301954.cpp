#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#define in(a) a=read()
#define REP(i,k,n) for(int i=k;i<=n;i++)
using namespace std;
inline int read(){
    int x=0,f=1;
    char ch=getchar();
    for(;!isdigit(ch);ch=getchar())
        if(ch=='-')
            f=-1;
    for(;isdigit(ch);ch=getchar())
       x=x*10+ch-'0';
    return x*f;
}
int main(){
    char ch[100010];
    int n,m;
    in(n);
    scanf("%s",ch+1);
    in(m);
    REP(i,1,n){
    	if(ch[i]!=ch[m])  cout<<"*";
    	else  cout<<ch[i];
    }
	return 0;
}