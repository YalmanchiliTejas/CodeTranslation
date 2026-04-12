#include<bits/stdc++.h>
using namespace std;
typedef __int128 ll;
const int maxn=2e5+10;
const int mod=1e9+7;
inline __int128 read(){
   int X=0,w=0; char ch=0;
   while(!isdigit(ch)) {w|=ch=='-';ch=getchar();}
   while(isdigit(ch)) X=(X<<3)+(X<<1)+(ch^48),ch=getchar();
   return w?-X:X;
}
inline void print(__int128 x){
   if(x<0){putchar('-');x=-x;}
   if(x>9) print(x/10);
   putchar(x%10+'0');
}
int n;
ll f[maxn];
ll num[maxn];
ll ans,sum;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)f[i]=read(),num[i]=num[i-1]+f[i];
	for(int i=1;i<=n-1;i++)sum+=f[i]*(num[n]-num[i]);
	print(sum%mod);
	return 0;
}
/*
4
10000
10000
10000
10000
*/