#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b)      for(int i=a;i<=b;i++)
#define revp(i,b,a)     for(int i=b;i>=a;i--)

int n,arr[22],cnt=1,maxi;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    

    cin>>n;
    rep(i,1,n)
        cin>>arr[i];
    maxi=arr[1];
    rep(i,2,n)
    {
        if(arr[i]>=maxi)
            cnt++,maxi=arr[i];
    }
    cout<<cnt;
}
