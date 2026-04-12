#include<bits/stdc++.h>
#define ll long long
#define INF 2e9
#define mo 1000000007
using namespace std;
struct Info{ll p1,p2;};
int a[1010],n;
ll po(ll x,ll y){ll z=1;while (y){if (y%2==1)z=(x*z)%mo;x=(x*x)%mo;y/=2;}return z;}
Info work(int l,int r,int x){
	int mi=INF;
	Info z,y;
	ll c1=1,c2=1,c3=0;
	for(int i=l;i<=r;i++)mi=min(mi,a[i]);
	for(int i=l;i<=r;i++)if(a[i]==mi)c3++;
	for(int i=l,j;i<=r;i=j+1){
		j=i;
		if (a[i]>mi){while (a[j+1]>mi)j++;y=work(i,j,mi);c1=c1*y.p1%mo,c2=c2*(y.p1+y.p2)%mo;}
	}
	z.p1=c1*po(2,mi-x)%mo;
	z.p2=(c2*po(2,c3)+c1*(po(2,mi-x)-2+mo))%mo;
	return z;
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	cout<<work(1,n,0).p2<<endl;
	return 0;
}