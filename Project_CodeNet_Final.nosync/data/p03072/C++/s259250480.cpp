#include "bits/stdc++.h"
#define en "\n"
using namespace std;
const int M=1e5+100;



int main()
{
    int n,ans=0,ma=0,tem;
    cin>>n;
    while(n--)
    {
        cin>>tem;
        if(tem>=ma)ans++;
        ma=max(ma,tem);
    }
    cout<<ans<<en;
    return 0;
}
