#include<bits/stdc++.h>
#define int long long
using namespace std;
 

signed main()
{
 
ios_base::sync_with_stdio(false);
cin.tie(NULL);  
cout.tie(0);   
 
 
#ifndef ONLINE_JUDGE
    if(fopen("INPUT.txt","r"))
    {
    freopen ("INPUT.txt" , "r" , stdin);
    freopen ("OUTPUT.txt" , "w" , stdout);
    }
#endif    

    int n,k;
    cin>>n>>k;
    if(k==0)
    {
        cout<<n*n;
    }
    else
    {
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            ans-=(n/i)*(min(k-1,i-1)+1);
            ans-=(min(k-1,n%i))+1;
            ans+=n+1;
        }
        cout<<ans<<endl;
    }
    
    
}