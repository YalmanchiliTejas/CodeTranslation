#include <bits/stdc++.h>
using namespace std;
const double eps=1e-2;
const int MAXN = 55;
typedef long long LL;
LL a[MAXN], b[MAXN];

int main()
{
    int n; LL x; cin>>n>>x;
    a[0]=1,b[0]=1;
    for(int i=1; i<=n; i++) {
        a[i]=a[i-1]*2+3;
        b[i]=b[i-1]*2+1;
    }
    LL sum = 0, ans = 0;
    for(int i=n; i>=0; i--) {
        if(x==a[i]/2) {
            ans+=b[i]/2;
            break;
        }
        if(x > a[i]/2) {
            ans+=(b[i-1]+1);
            x-=(a[i]/2+1);
        }
        else {
            x--;
        }
    }
    cout<<ans<<endl;
    return 0;
}
