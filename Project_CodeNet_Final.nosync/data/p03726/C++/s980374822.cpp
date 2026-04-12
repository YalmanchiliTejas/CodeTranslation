#include<bits/stdc++.h>
#define mo 1000000007
#define pi 3.1415926535898 
using namespace std;
long long read(){
    long long xx=0,flagg=1;
    char ch=getchar();
    while((ch<'0'||ch>'9')&&ch!='-')
        ch=getchar();
    if(ch=='-'){
        flagg=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        xx=xx*10+ch-'0';
        ch=getchar();
    }
    return xx*flagg;
}
void pus(long long xx,long long flagg){
    if(xx<0){
        putchar('-');
        xx=-xx;
    }
    if(xx>=10)
        pus(xx/10,0);
    putchar(xx%10+'0');
    if(flagg==1)
        putchar(' ');
    if(flagg==2)
        putchar('\n');
    return;
}
long long ksm(long long u,long long v){
	long long o=1;
	while(v){
		if(v&1)
			o=o*u%mo;
		u=u*u%mo;
		v>>=1;
	}
	return o;
}
int n,k,i,sum[200005],x,y,flag;
int top,nex[200005],to[200005],fir[100005];
void lj(int u,int v){
	top++;
	nex[top]=fir[u];
	fir[u]=top;
	to[top]=v;
}
void ss(int u,int v){
	for(int top1=fir[v];top1;top1=nex[top1])
		if(to[top1]!=u)
			ss(v,to[top1]);
	if(sum[v]==0){
		if(v==1)
			flag=1;
		sum[u]++;
	}	
	if(sum[v]==2)
		flag=1;
}
int main(){
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
   	n=read();
   	for(i=1;i<n;i++){
   		x=read();
		y=read();
		lj(x,y);
		lj(y,x);
   	}
   	ss(1,1);
   	if(flag==1)
   		printf("First\n");
   	else
   		printf("Second\n");
    return 0;
}