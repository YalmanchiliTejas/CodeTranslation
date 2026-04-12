#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=200005,p=1000000007;
int read(){
	int f=1,g=0;
	char ch=getchar();
	for (;!isdigit(ch);ch=getchar()) if (ch=='-') f=-1;
	for (;isdigit(ch);ch=getchar()) g=g*10+ch-'0';
	return f*g;
}
int n,m,cnt,a[N],f[N];
char ch[N];
int calc(int n,int l,int r){
	f[0]=1;
	int s=0;
	for (int i=1;i<=n;i++){
		if (i>=l) s=(s+f[i-l])%p;
		f[i]=s;
		if (i>=r) s=(s-f[i-r]+p)%p;
	}
	int ans=0;
	for (int i=l;i<=r;i++)
		ans=(ans+(ll)f[n-i]*i)%p;
	return ans;
}
int main(){
	n=read();m=read();
	scanf(" %s",ch+1);
	cnt=0;
	for (int i=1;i<=m;i++)
	if (ch[i]==ch[1]) a[cnt]++;
	else cnt++;
	if (cnt==0) printf("%d\n",(calc(n,2,n)+1)%p);
	else if (n&1) puts("0");
	else{
		int r=a[0]+1-(a[0]&1);
		for (int i=1;i<cnt;i++)
		if (a[i]%2==1) r=min(r,a[i]);
		printf("%d\n",calc(n/2,1,(r+1)/2)*2%p);
	}
	return 0;
}