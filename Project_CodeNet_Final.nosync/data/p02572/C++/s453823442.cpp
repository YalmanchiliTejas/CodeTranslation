#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int n,i,j,sum=0;
    while(cin>>n)
    {
        long long int p=0,x;
        vector<long long int>v,u;
        long long int c=1000000007;
        for(i=0; i<n; i++)
        {
           cin>>x;
           v.push_back(x);
        }
        for(i=n-1;i>=0;i--)
        {
            sum=sum+v[i];
            u.push_back(sum);
        }
        reverse(u.begin(),u.end());
        long long int ans=0;
        for(i=0;i<n;i++)
        {
            p=u[i]-v[i];
            ans= ((ans%c)+(((p%c)*(v[i]%c))%c))%c;
        }
        cout<<ans%c<<endl;
    }
}
