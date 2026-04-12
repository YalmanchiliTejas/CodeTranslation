#include <bits/stdc++.h>
#include <cmath>
#include <map> 
using namespace std;
long long komb;
#define mod 1000000007 // nmax 2*10^5 llmax 8*10^18
long long bul(long long n,long long m)
{
	long long son=((((((((n * (n+1) * (2*n+1)) /6) + (n*(n+1)/2)) / 2)%mod)  *  m)%mod)  *  m)%mod;
	return son;
}

long long fcomb(long long n, long long r)
{
	long long i,mi=min(n,n-r),nmu=1,rmu=1,fmo,rmuinv=1;
	for(i=1;i<=mi;i++)
	{
		nmu*=n--;	nmu%=mod;
		rmu*=i; rmu%=mod;
	}
	for(fmo=mod-2;fmo;fmo>>=1)
	{
		rmuinv=(rmuinv*((fmo%2)?rmu:1))%mod;
		rmu*=rmu; rmu%=mod;
	}
	return (nmu*rmuinv)%mod;
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	long long n,m,k,i;
	long long yaz=0;
	cin>>n>>m>>k;

	komb=((((m*n-2)%mod)*((m*n-3)%mod)/2)%mod);
	if(k==2 || k==3) komb=1;
	yaz=(bul(n-1,m)+bul(m-1,n))*fcomb((m*n-2),k-2);
	yaz%=mod;

	cout<<yaz<<endl;
	return 0;
}