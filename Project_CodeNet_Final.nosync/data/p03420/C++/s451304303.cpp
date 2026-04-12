#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    
    int n,k;
    cin>>n>>k;
    
    ll ans = 1LL*n*n;
    
    if(k==0){
        cout << ans << endl;
        return 0;
    }
    
    for(int b=1; b<=n; b++){
        if(b>k)ans -= n/b * k + min( k, n%b+1 ) - 1;
        else ans -= n;
    }
    
    cout << ans << endl;
}