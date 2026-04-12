#include <bits/stdc++.h>
 
using namespace std;
 
const int MOD=1e9+7;
const double PI=3.14159265359;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n,k;
    cin>>n>>k;
    long long ans=0;
    if(!k){
        cout<<(long long)n*n;
        return 0;
    }
    
    for(int b=k+1; b<=n; b++){
        int t=b-k;
        int left=k, right=b-1;
        for(int shift=0; left<=n && right<=n; shift++){
            if(left<=n && right<=n){
                ans+=t;
                left+=b, right+=b;
            }
        }
        if(left<=n && right>n){
            ans+=n-left+1;
        }
    }
    cout<<ans;
   
    return 0;
}