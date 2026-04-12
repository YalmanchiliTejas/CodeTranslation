#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
long long n,k,ans;
int main()
{
    cin>>n>>k;
    if(!k)
    {
        cout<<n*n;
        return 0;
    }
    for(int i=k;i<=n;i++)  
    {  
        ans+=n/i*(i-k);  
        if(n%i>=k)  
            ans+=n%i-k+1;  
    }  
    cout<<ans;
}