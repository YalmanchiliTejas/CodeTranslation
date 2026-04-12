#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,k;
    cin >> n >> k;
    if(k==0){
        cout << 1LL*n*n << endl;
        return 0;
    }
    long long ans=0;
    for(int i=1;i<=n;i++){  // iterate over divisor
        ans+=max(0LL,1LL*(i-k)*(n/i));
        int rem=n%i;
        ans+=max(0,(rem-k+1));
    }
    cout << ans << endl;
    return 0;
}
