#include <bits/stdc++.h>
typedef long long int lli;
typedef unsigned long long int ulli;

using namespace std;
lli con = (int)pow(10,9) + 7;

int main()
{
    int n;
    cin>>n;
    lli arr[n];
    lli pref[n];
    
    lli sum=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        sum+=arr[i];
    }
    pref[0] = arr[0];
    for(int i=1;i<n;i++){
        //cin>>arr[i];
        //sum+=arr[i];
        pref[i] = pref[i-1] + arr[i];
    }
    
    
    lli res = 0;
    
    for(int i=0;i<n;i++){
        //cin>>arr[i];
        //sum+=arr[i];
        
        res += ( (arr[i] % con)*((sum - pref[i]) % con ) )%con;
    }
    cout<<(res)%con<<"\n";
    
    return 0;
}