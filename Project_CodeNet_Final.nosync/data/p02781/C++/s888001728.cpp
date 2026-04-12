#include <bits/stdc++.h>
using namespace std;
template<class t> inline t read(t &x){
    x=0;char c=getchar();bool f=0;
    while(!isdigit(c)) f|=c=='-',c=getchar();
    while(isdigit(c)) x=(x<<1)+(x<<3)+(c^48),c=getchar();
    if(f) x=-x;return  x;
}
template<class t> inline void write(t x){
    if(x<0){putchar('-'),write(-x);}
    else{if(x>9)write(x/10);putchar('0'+x%10);}
}

#define int long long

const int N=105;
int f[N][5][2],n,k;
char s[N];

int dp(int x,int k,bool op){
	if(x==n+1) return k==0;
	int &now=f[x][k][op];
	if(now!=-1) return now;
	now=0;
	if(s[x]=='0') now+=dp(x+1,k,op);
	else now+=dp(x+1,k,1);
	if(!k||(s[x]=='0'&&!op)) return now;
	if(op) now+=9*dp(x+1,k-1,1);
	else now+=(s[x]-'0'-1)*dp(x+1,k-1,1)+dp(x+1,k-1,0);
	return now;
}

signed main(){
	scanf("%s",s+1);read(k);n=strlen(s+1);
	memset(f,-1,sizeof f);
	write(dp(1,k,0));
}