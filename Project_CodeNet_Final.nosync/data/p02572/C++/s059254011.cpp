#include <bits/stdc++.h>
using namespace std;
int main(void){
    long n; cin >> n;
    long total = 0;
    long ans = 0;
    vector<long> v(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
        total += v[i];
        total %= 1000000007;
    }
    for(int i=0;i<n-1;i++){
        total -= v[i];
        total %= 1000000007;
        ans += total*v[i];
        ans %= 1000000007;
    }
    if(ans < 0)ans = 1000000007 + ans;
    cout << ans << endl;
}