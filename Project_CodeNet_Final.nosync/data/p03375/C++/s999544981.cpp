#include <iostream>
#include <cstdio>
#include <cassert>
using namespace std;
typedef long long LL;
const int MAXN=3000;
int n;
LL mods;
struct M{
	LL x;
	M (){
		x=0;
	}
	M (LL angka){
		if(angka>=mods||angka<=-mods)
			angka%=mods;
		if(angka<0)
			angka+=mods;
		x=angka;
	}
	
	M operator + (const M &other) const{
		return M(x+other.x);
	}
	M operator - (const M &other) const{
		return M(x-other.x);
	}
	M operator * (const M &other) const{
		return M(x*other.x);
	}
	M operator - () const{
		return M (-x);
	}
	bool operator == (const M &other) const{
		return x==other.x;
	}
};
M dp[MAXN+5],dp2[MAXN+5][MAXN+5],dp3[MAXN+5][MAXN+5],fakt[MAXN+5],pangpang[MAXN+5],ans;
M DnC(M angka,LL pangkat){
	if(pangkat==0)
		return 1;
	M ret=DnC(angka,pangkat>>1);
	ret=ret*ret;
	if(pangkat&1LL)
		ret=ret*angka;
	return ret;
}
M inv(M angka){
	M ret=DnC(angka,mods-2);
	assert(ret*angka==1);
	return ret;
}
M kombin(int N,int K){
	if(K>N)
		return 0;
	return fakt[N]*inv(fakt[K])*inv(fakt[N-K]);
}
void isipangpang(){
	pangpang[0]=2;
	for(int i=1;i<=n;i++)
		pangpang[i]=pangpang[i-1]*pangpang[i-1];
}
void isifakt(){
	fakt[0]=1;
	for(int i=1;i<=n;i++)
		fakt[i]=fakt[i-1]*i;
}
void isidp3(){
	//basecase
	dp3[0][0]=1;
	for(int i=1;i<=n;i++)
		dp3[0][i]=0;
	
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=n;j++)
			dp3[i][j]=((j)?dp3[i-1][j-1]:0)+dp3[i-1][j]*(j+1);
	}
}
void isidp2(){
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=i;j++)
		{
			dp2[i][j]=dp3[i][j]*DnC(2,(n-i)*j)*(pangpang[n-i]);
		}
	}
}
void isidp(){
	for(int i=1;i<=n;i++)
	{
		dp[i]=0;
		for(int j=0;j<=i;j++)
			dp[i]=dp[i]+dp2[i][j];
	}
}
void isians(){
	ans=pangpang[n];
	for(int i=1,status=-1;i<=n;i++,status=-status)
		ans=ans+kombin(n,i)*dp[i]*status;
}
int main()
{
	cin>>n>>mods;
	isipangpang();
	isifakt();
	isidp3();
	isidp2();
	isidp();
	isians();
	cout<<ans.x<<endl;
}