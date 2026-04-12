#include<bits/stdc++.h>
#define F first
#define S second
#define mod 1000000007

using namespace std;
pair<int,int> arr[300000];
int main()
{
    int i,n;
    cin>>n;
    
    for(int i=0;i<n;i++){int a;cin>>a;arr[i]=make_pair(a,i);}
    
    sort(arr,arr+n);
    int ans[300000];
    
    int p1= n/2,p2=n/2-1;
    for(i=0;i<n;i++)
    {
        if(i<=p2)ans[arr[i].S]=arr[p1].F;
        if(i>=p1)ans[arr[i].S]=arr[p2].F;
    }
    for(i=0;i<n;i++)cout<<ans[i]<<endl;
    return 0;
}
