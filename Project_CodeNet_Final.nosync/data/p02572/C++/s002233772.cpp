#include<iostream>
#include<iomanip>
#include<cassert>
#include<math.h>
#include<complex>
#include<algorithm>
#include<utility>
#include<queue>
#include<string.h>
#include<string>
#include<set>
#include<map>
#include<unordered_map>
#include<functional>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const ll INF=2e18;
const ll MOD=1e9+7;

ll N;
ll A[200010];
ll sum[200010];
int main(){
    cin>>N;
    for(ll i=0;i<N;i++) cin>>A[i];
    sum[0]=A[0];
    for(ll i=1;i<N;i++){
        sum[i]=(sum[i-1]+A[i])%MOD;
    }
    ll ans=0;
    for(ll i=0;i<N-1;i++){
        ans=(ans+A[i]*(sum[N-1]-sum[i]+MOD)%MOD)%MOD;
    }
    cout<<ans<<endl;
    return 0;
}