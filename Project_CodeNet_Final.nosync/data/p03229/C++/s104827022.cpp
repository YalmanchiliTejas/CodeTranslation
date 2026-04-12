#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define int long long
signed main(){
//int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.rbegin(),a.rend());

    int ans=0;
    for(int i = 0; i < n/2; i++) ans+=a[i];
    for(int i = n/2; i < n; i++) ans-=a[i];
    ans*=2;
    ans+=a[n/2];
    if(n%2) ans+=a[n/2+1];
    else ans-=a[n/2-1];

    sort(a.begin(),a.end());
    int rans=0;
    for(int i = 0; i < n/2; i++) rans+=a[i];
    for(int i = n/2; i < n; i++) rans-=a[i];
    rans*=2;
    rans+=a[n/2];
    if(n%2) rans+=a[n/2+1];
    else rans-=a[n/2-1];
    rans*=-1;

    ans=max(rans,ans);
    cout << ans << "\n";
    return 0;
}