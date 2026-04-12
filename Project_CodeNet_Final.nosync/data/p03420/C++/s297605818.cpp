#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
#define MOD 1000000007
const int INF = 1LL<<30;


int main(){
    ll n,k;
    cin>>n>>k;
    ll ans=0;
    if(k==0){
        cout<<n*n<<endl;
        return 0;
    }
    for(int i=1;i<=n;i++){
        if(i<=k) continue;
        ll tmp=0;
        ll q=n/i;
        tmp+=(i-k)*q;
        ll r=n%i;
        if(r!=0) tmp+=max(0LL,r-k+1);
        //cout<<i<<" "<<tmp<<endl;
        ans+=tmp;
    }

    cout<<ans<<endl;
}