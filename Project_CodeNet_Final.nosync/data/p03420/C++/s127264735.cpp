#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define int ll
typedef pair<int,int> pii;
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define all(a) (a).begin(),(a).end()
#define pb emplace_back

signed main(){
    int n,k;
    cin>>n>>k;
    if(k==0){
        cout<<n*n<<endl;
        return 0;
    }
    
    int ans = 0;
    for(int b=k+1;b<=n;b++){
        ans += (b-k) * (n/b) + max<ll>(0,n+1-(n/b*b+k));
    }
    cout<<ans<<endl;
}
