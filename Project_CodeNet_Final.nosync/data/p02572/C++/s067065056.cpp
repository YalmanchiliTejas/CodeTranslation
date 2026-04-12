#include <stdio.h>

#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
const ll maxn = 2e5 + 111;
const ll mod=1e9+7;
ll a[maxn];
ll pre[maxn];
int main() {
    int n;
    cin>>n;
    ll ans=0;
    for(int i=1;i<=n;++i){
        scanf("%lld",a+i);
        pre[i]=(pre[i-1]+a[i])%mod;
    }
    for(int i=2;i<=n;++i){
        ans=(ans+pre[i-1]*a[i])%mod;
    }
    cout<<ans%mod<<endl;
    return 0;
}