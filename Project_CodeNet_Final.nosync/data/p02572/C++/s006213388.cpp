#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n, tot=0, ans=0;
    cin >> n;
    long long a[n+1];
    for (int i=1; i<=n; i++){
        cin >> a[i];
        tot+=a[i];
    }
    for (int i=1; i<n; i++){
        tot-=a[i];
        ans+=(tot)%(long long)(1e9+7)*a[i];
        ans%=(long long)(1e9+7);
    }
    cout << ans << endl;
    return 0;
}