#include <bits/stdc++.h>   
using namespace std;     
int main()  
{  
    long long n,k,ans=0;  
    cin >> n>> k;  
    if(k==0) ans=n*n;  
    else  
    {  
        for(int b=k+1;b<=n;b++)  
        {  
        ans+=(n/b)*(b-k);  
        if(n%b>=k) ans+=n%b-k+1;  
        }  
    }  
    printf("%lld\n",ans);  
    return 0;  
}  