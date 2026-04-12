#include <bits/stdc++.h>
using namespace std;

long long n,k,rez;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin>>n>>k;

    for(long long i=1;i<=n;i++)
    {
        long long p=n/i;
        long long r=n-i*p;
        rez+=p*max((long long)0,i-k)+max((long long)0,r-k+1);
    }
    if(k==0)
        rez-=n;

    cout<<rez<<endl;

    return 0;
}
