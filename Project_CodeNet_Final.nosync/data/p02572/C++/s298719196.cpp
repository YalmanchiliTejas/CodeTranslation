/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> a(n);
    int mod=1e9+7;
    for(int i=0;i<n;i++){
        cin>>a[i];
        a[i]%=mod;
    }
    long long int sum=0;
    for(int i=0;i<n;i++){
        sum+=a[i];
        sum%=mod;
    }
    long long int ans=0;
    for(int i=0;i<n;i++){
        sum-=a[i];
        if(sum<=0){
            sum+=mod;
            //sum%=mod;
        }
        ans+=(a[i]*sum);
        ans%=mod;
    }
    cout<<ans<<endl;
    return 0;
}
