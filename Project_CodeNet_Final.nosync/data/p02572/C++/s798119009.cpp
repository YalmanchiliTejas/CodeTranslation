#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9+7;
int main()
{
    unsigned long long sum = 0 ;
    int n ;
    cin >> n ;
    long long arr[n+5]{};
    long long pre[n+5]{};
    for(int i = 0 ;i < n ; i++){
        cin >> arr[i];
        sum+=arr[i];
    }
    for(int i = 0 ; i < n ; i++){
        if(i==0)
            pre[i] = arr[i];
        else
            pre[i] = arr[i] + pre[i-1];
    }
    unsigned long long ans = 0 ;
    for (int i = 0 ; i < n ; i++){
        unsigned long long a = sum - pre[i];
        unsigned long long b = ( (arr[i]%mod) * (a%mod) )%mod;
        ans = ( (ans%mod) + (b%mod) )%mod;
    }
    cout << ans << endl;
    return 0;
}
