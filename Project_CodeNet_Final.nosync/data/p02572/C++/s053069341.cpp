#include <bits/stdc++.h>
const int MAX=2e5+10;
const int modn=1e9+7;
typedef long long ll ;
#define int ll
#define endl '\n'
#define cwk     freopen("D:\\workplace\\CLion\\in.in","r",stdin),freopen("D:\\workplace\\CLion\\out.out","w",stdout)
using namespace std;
int n,m,d,t,s;
string p,q;
int a[MAX],b[MAX];
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[i]=b[i-1]+a[i];
        b[i]%=modn;
    }
    ll sum=0;
    for(int i=2;i<=n;i++){
        ll now=a[i]*b[i-1]%modn;
        sum+=now;
        sum%=modn;
    }
    cout<<sum;
}
signed main() {
    //ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    //cwk;
    int _=1;
    //cin>>_;
    while(_--){
        solve();
    }
    return 0;
}