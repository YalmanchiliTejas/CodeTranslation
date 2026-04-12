#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<queue>
#include<map>
#include<stack>
#include<string>
#include<algorithm>
#include<cmath>
#define rg register
#define il inline
using namespace std;
typedef long long ll;
ll read(){
    ll ans=0,flag=1;char ch;
    while((ch=getchar())<'0'||ch>'9') if(ch=='-') flag=-1;ans=ch^48;
    while((ch=getchar())>='0'&&ch<='9') ans=(ans<<3)+(ans<<1)+(ch^48);
    return flag*ans;
}
int main(){
    int n=read();
    char buff[1005];
    scanf("%s",buff);
    int t=read();
    for(rg int i=0;i<n;i++){
        if(buff[i]!=buff[t-1]) putchar('*');
        else putchar(buff[i]);
    }
    return 0;
}