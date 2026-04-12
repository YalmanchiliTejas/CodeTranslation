#include <bits/stdc++.h>
using namespace std;

#define int long long
#define debug(x) cout<<#x<<" "<<x<<endl;

const int N=1e6+5;
const double eps=1e-9;
const int INF=1e18;
const int P=1e9+7;

int a[N];

signed main()
{
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
    int n;cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    int res=0,sum=0;
    for(int i=1;i<=n;i++){
        sum+=a[i];
        res+=(sum-a[i])%P*a[i],res%=P;
    }
    cout<<res<<endl;
    return 0;
}

//Created Time  :2020/8/29 20:00:20
