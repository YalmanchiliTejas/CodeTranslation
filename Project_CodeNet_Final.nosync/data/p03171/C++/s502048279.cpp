#include<bits/stdc++.h>
using namespace std;

long long int maxm[3001][3001];

long long int recursivedp(long long int arr[],long long int i,long long int j,long long int sum)
{
    
    if((i+1)==j)
        return max(arr[i],arr[j]);
    else if (maxm[i][j]!=-1)
        return maxm[i][j];
    else
    {
        maxm[i][j]=max(sum-recursivedp(arr,i+1,j,sum-arr[i]),sum-recursivedp(arr,i,j-1,sum-arr[j]));
    }
    return maxm[i][j];
        
}

int main()
{
    long long int t,n,k,ans,i,j,sum,a[3001],ans2;
    
    for(i=0;i<3001;i++)
    {
        for(j=0;j<3001;j++)
        {
            maxm[i][j]=-1;
        }
    }
    cin>>n;
    sum=0;
    for(i=0;i<n;i++)
        {cin>>a[i];
        sum+=a[i];}
    if (n==1)
        cout<<a[0]<<endl;
    else{
    ans=recursivedp(a,0,n-1,sum);
    ans2=sum-ans;
    
    cout<<ans-ans2<<endl;
    }
    
    
}