#include <bits/stdc++.h>
using namespace std;
#define lli long long
const lli mod = (lli)(1e9+7);

int main() 
{
    int n;
    cin >> n;
    
    vector<int> v(n);
    
    lli sum = 0, ans = 0;
    
    for(int i=0;i<n;i++){
        cin >> v[i];
        sum += 1LL*v[i];
        sum %= mod;
    }
    
    for(int i=0;i<n;i++){
        sum -= v[i];
        if(sum<0) sum += mod;
        sum %= mod;
        lli temp = v[i];
        temp *= sum;
        temp %= mod;
        ans+=temp;
        ans%=mod;
    }
    
    cout<<ans<<endl;
    return 0;
}