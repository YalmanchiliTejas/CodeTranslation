#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n,k;
    while(cin>>n>>k)
    {
        long long l=n-k;
        long long s=0;
        for(int i=1;i<=l;i++)
        {
            long long r=n/(k+i);
            s+=r*i;
            if(n%(k+i)>=k)
                s+=n%(k+i)-k+1;
        }
        if(k==0)
            s-=n;
        cout<<s<<endl;
    }
    return 0;
}
