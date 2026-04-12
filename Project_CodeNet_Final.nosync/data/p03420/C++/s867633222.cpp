#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll,ll> Pl;
#define all(a) (a).begin(),(a).end()
#define rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(ll i=(a);i<(b);i++)
#define rrep(i,n) for(ll (i)=(n)-1;(i)>=0;i--)
#define SHOW(x) cout << #x << ": " << x << endl;
const ll INF=1e18,MOD = 1e9+7;
const int iINF = 1e9;

int main(){
    ll n,k,ans = 0;
    cin>>n>>k;
    repi(i,k + 1,n + 1){//bを固定して考えてみる
        ans += n / i * max(0LL,i - k);
        ans += max(0LL, n % i + 1 - k);
    }
    if(k == 0)cout<<n * n<<endl;
    else cout<<ans<<endl;
}
