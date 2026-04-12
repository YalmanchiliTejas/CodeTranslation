#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main() 
{
    long n;
    cin>>n;
    long l[n+1];
    l[0]=0;
    for(int i=1;i<=n;i++)
    cin>>l[i];
    long s=0;
    for(int i=0;i<=n;i++)
    s+=l[i];
    long long ans=0,infin=pow(10,9)+7;
    for(int i=n;i>=2;i--)
    {
        s=s-l[i];
        ans=(ans+(l[i]%infin)*(s%infin))%infin;
    }
    cout<<ans<<endl;
    return 0;
}



