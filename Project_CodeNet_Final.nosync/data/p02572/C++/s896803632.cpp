// This file is a "Hello, world!" in C++ language by GCC for wandbox.
#include <iostream>
#include <cstdlib>
#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
int main(){
    int n,i,j,x;
    long long int ans=0,a[200014],b[200014];
    b[0]=0;
    cin >> n;
    long long int MOD=1000000007;
    
    for(i=0;i<n;i++)
    {
        cin >> a[i];
    }
    for(i=1;i<n+1;i++)
    {
        b[i]=a[i-1]+b[i-1];
    }
    for(i=0;i<n;i++)
    {
        
        ans+=(b[n]-b[i+1])%MOD*a[i]%MOD;
        ans=ans%MOD;
    }
    cout << ans << endl;
}
