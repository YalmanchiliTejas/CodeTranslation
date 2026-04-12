#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int i,j,m=0,n,sum=0,in;
    long long int k=1000000007;
 
 
    cin>>n;
    vector<long long int>a;
    for(i=0;i<n;i++)
        {
            cin>>in;
            a.push_back(in);
            sum=sum+a[i];
 
        }
        for(i=0;i<n-1;i++)
        {
            sum=sum-a[i];
            m=m+(((sum%k)*(a[i]%k))%k);
            m%=k;
 
        }
        cout<<m<<endl;
}