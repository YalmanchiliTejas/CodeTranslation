#include <iostream>

using namespace std;
typedef long long ll;
bool f[100010];
ll a[100010];
int main(){
    ll i,n,x,m; cin >> n >> x >> m;
    for(i=0;i<m;i++) f[i] = false;
    a[0] = x;
    for(i=1;i<=m;i++) a[i] = a[i - 1]*a[i - 1]%m; 
    int l = -1,r = -1;
    for(i=1;i<=m;i++){
        if(f[a[i]]){
            r = i;
            break;
        }
        f[a[i]]= true;
    }
    for(i=0;i<=m;i++){
        if(a[i]==a[r]){
            l = i; break;
        }
    }
    ll sum = 0,sum1 = 0;
    for(i=0;i<l;i++) sum += a[i];
    for(i=l;i<r;i++) sum1 += a[i];
    n -= l;
    ll ti = n/(r - l),ans = ti*sum1 + sum;
    n -= ti*(r - l);
    for(i=l;i<n + l;i++) ans += a[i];
    cout << ans << endl;
}