/*Whose woods these are I think I know.
His house is in the village though;
He will not see me stopping here
To watch his woods fill up with snow.

My little horse must think it queer
To stop without a farmhouse near
Between the woods and frozen lake
The darkest evening of the year.

He gives his harness bells a shake
To ask if there is some mistake.
The only other sound’s the sweep
Of easy wind and downy flake.

The woods are lovely, dark and deep,
But I have promises to keep,
And miles to go before I sleep,
And miles to go before I sleep.*/

#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define pb push_back
#define fi first
#define se second
#define MOD 1000000007
const int maxn= 100010;
lli modexp(lli x, lli y)
{
    lli res=1ll;
    x%=MOD;
    while(y>0ll)
    {
        if(y&1ll)
            res=(res*x)%MOD;
        y>>=1ll;
        x=(x*x)%MOD;
    }
    return res;
}
lli modinv(lli n)
{
    return modexp(n,MOD-2ll);
}
lli BinCoeff(lli n, lli r)
{
    if(r==0ll)
        return 1ll;
    lli aux[n+1];
    aux[0]=1ll;
    for(lli i=1ll;i<=n;++i)
        aux[i]=aux[i-1]*i%MOD;
    return (aux[n]*modinv(aux[r])%MOD*modinv(aux[n-r])%MOD)%MOD;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n=0,m=0;lli k=0ll,sum=0ll;
    cin>>n>>m>>k;
    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j)
        {
            lli x=1ll*(n-i)*(m-j);
            x%=MOD;
            x=1ll*x*(i+j);
            x%=MOD;
            if(i!=0&&j!=0)
                x*=2ll;
            sum=(sum+x)%MOD;
        }
    cout<<(1ll*sum*BinCoeff(1ll*n*m-2ll,k-2ll))%MOD<<endl;
}
