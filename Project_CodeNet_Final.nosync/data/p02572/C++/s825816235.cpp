#include<bits/stdc++.h>
using namespace std;
int main()
{
    unsigned long long i,j,m=0,n,sum=0;
    const long int k=1000000007;


    cin>>n;
    vector<long long>a;
    for(i=0;i<n;i++)
        {
            cin>>j;
            a.push_back(j);
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
