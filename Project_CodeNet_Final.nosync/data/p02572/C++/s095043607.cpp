#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int N=2e5+1000;
const LL P=1e9+7;
int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
void print(int x){
    if(x>9) print(x/10);
    putchar(x%10+'0');
}
int n;
LL a[N],b[N];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%lld",&a[i]);
	b[n+1]=0;
	for(int i=n;i>=1;--i){
		b[i]=(b[i+1]+a[i])%P;
	}
	LL ans=0;
	for(int i=1;i<n;++i){
		ans=ans+a[i]*b[i+1]%P;
	}
	ans=ans%P;
	cout<<ans<<endl;
	return 0;
}