//daca nr de A pe poz impare + nr de B poz pare>n/2 nu se poate, altfel se poate
// la fel B,A
#include<iostream>
#define MOD 998244353

using namespace std;

int Fact[10000005],Inv[10000005],P2[10000005];

int put(int a, int b)
{
    int rez=1;
    for(int i=0; (1<<i)<=b; i++)
    {
        if((1<<i)&b)
            rez=(1LL*rez*a)%MOD;
        a=(1LL*a*a)%MOD;
    }
    return rez;
}

int comb(int n, int k)
{
    return (1LL*((1LL*Fact[n]*Inv[k])%MOD)*Inv[n-k])%MOD;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    int n;
    cin>>n;
    int rez=put(3,n);

    Fact[0]=1;
    for(int i=1; i<=n; i++)
        Fact[i]=(1LL*Fact[i-1]*i)%MOD;

    Inv[n]=put(Fact[n],MOD-2);
    for(int i=n-1; i>=0; i--)
        Inv[i]=(1LL*Inv[i+1]*(i+1))%MOD;

    P2[0]=1;
    for(int i=1; i<=n/2; i++)
        P2[i]=(2LL*P2[i-1])%MOD;

    for(int i=n/2+1; i<=n; i++)
    {
        int act=0;
        act=(act+(2LL*comb(n,i)*P2[n-i]%MOD))%MOD;
        rez=(rez-act+MOD)%MOD;
    }

    cout<<rez<<"\n";
    return 0;
}
