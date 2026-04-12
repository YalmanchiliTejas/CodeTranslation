#include <bits/stdc++.h>
#define inc(i,a,b) for(register int i=a;i<=b;i++)
using namespace std;
long long KSM(long long a,long long b,long long p){
	long long res=1;
	while(b){
		if(b&1) res=res*a%p;
		a=a*a%p;
		b/=2;
	}
	return res%p;
}
long long c[3010][3010],s[3010][3010];
int main(){
	long long n,p;
	cin>>n>>p;
	c[0][0]=s[0][0]=1;
	inc(i,1,n+1){
		c[i][0]=1;
		inc(j,1,i){
			c[i][j]=(c[i-1][j]+c[i-1][j-1])%p;
			s[i][j]=(s[i-1][j-1]+(long long)j*s[i-1][j]%p)%p;
		}
	}
	long long ans=0;
	inc(i,0,n){
		long long sum=(i&1)?p-1:1;
		sum=sum*KSM(2,KSM(2,n-i,p-1),p)%p;
		sum=sum*c[n][i]%p;
		long long tmp=0;
		inc(j,0,i){
			tmp=(tmp+s[i+1][j+1]*KSM(KSM(2,(n-i),p)%p,j,p))%p;
		}
		sum=sum*tmp%p;
		ans=((ans+sum)%p+p)%p;
	}
	cout<<ans;
}