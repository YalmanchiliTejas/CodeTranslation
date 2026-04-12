/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int m=1000000007;

int main()
{
    ll n;
    cin>>n;
    ll a[n];
    ll sum=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        sum+=a[i];
    }
    ll c=0;
    for(int i=0;i<n;i++)
    {
       sum-=a[i];
       c+=((a[i]%m)*((sum)%m))%m;

    }
    cout<<c%m;
    

    return 0;
}
