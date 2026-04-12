#include <iostream>
#include <algorithm>
using namespace std;
long long sum,ans;
const int maxn=200000+5;
const int mod=1000000007;
int n,a[maxn];
int main(){
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=2;i<=n;i++){
        sum=(sum+a[i-1])%mod;
        ans=(ans+sum*a[i])%mod;
    }
    cout<<ans<<endl;
    return 0;
}
