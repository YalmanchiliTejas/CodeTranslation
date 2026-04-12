#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 1005;

char str[N];
int n,k,ans,f[N][5];

signed main() {
    cin>>str+1;
    n=strlen(str+1);
    for(int i=1;i<=n;i++) str[i]-='0';
    cin>>k;
    f[0][0]=1;
    for(int i=1;i<=n;i++) {
        f[i][0]=f[i-1][0];
        for(int j=1;j<=3;j++) {
            f[i][j]=f[i-1][j]+9*f[i-1][j-1];
        }
    }
    int cnt=0;
    for(int i=1;i<=n;i++) {
        //Calculate a[i] = 0
        if(str[i]) {
            if(k-cnt>=0) ans+=f[n-i][k-cnt];
        }
        //Calculate a[i] > 0
        if(str[i]>1) {
            if(k-cnt-1>=0) ans+=(str[i]-1)*f[n-i][k-cnt-1];
        }
        if(str[i]) ++cnt;
    }
    if(cnt==k) ++ans;
    cout<<ans;
}
