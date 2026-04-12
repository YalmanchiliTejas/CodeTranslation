/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9+7;

int main()
{
    int t=1;
    //cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        vector<int> arr(n);
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        
        long long suf[n];
        suf[n-1]=arr[n-1];
        
        for(int i=n-2;i>=0;i--)
        {
            suf[i]=(suf[i+1]+arr[i])%mod;
        }
        
        long long res=0;
        
        for(int i=0;i<n;i++)
        {
            if(i!=n-1)
            {
                res=(res+(arr[i]*suf[i+1])%mod)%mod;
            }
        }
        
        cout<<res<<endl;
    }
    return 0;
}
