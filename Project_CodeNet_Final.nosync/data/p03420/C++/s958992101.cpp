#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1000000007;
#define INF 1LL<<30
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()

int main() {
    ll n,k;
    cin>>n>>k;

    if(k==0){
        cout<<n*n<<endl;
        return 0;
    }

    ll ans=0;
    for(int i=k+1;i<=n;i++){
        int y=i-k;
        ans+=y*((n+1)/i);
        int r=(n+1)%i;
        ans+=max(r-k,0LL);
        //cout<<i<<" "<<ans<<endl;
    }

    cout<<ans<<endl;
}

