#include<iostream>

using namespace std;

int main ()
{
    int n,k,i;
    long long res=0;

    cin>>n>>k;

    for(i=k+1;i<=n;i++)
    {
        res+=(i-k)*(n/i);
        if(n%i>=k)
        {
            res+=n%i-k+1;
            if(k==0)res--;
        }
        //cout<<res<<endl;
    }

    cout<<res<<endl;

    return 0;
}
