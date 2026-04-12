#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
ll n;
cin>>n;
ll a[n];
for(ll i=0;i<n;i++)
cin>>a[i];
ll maxi=a[0];
ll c=1;
for(ll i=1;i<n;i++)
{
    if(maxi<=a[i])
    {
        maxi=a[i];
        c++;
    }
}
cout<<c<<endl;

}