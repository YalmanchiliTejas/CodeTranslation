#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef tuple<ll,ll,ll> T;
const long long INF = 1LL<<60;
const int MOD = 1000000000+7;
#define rev(s) (string((s).rbegin(), (s).rend()))
// cout << fixed << setprecision(10) << ans << endl; 有効桁数指定
// *min_element(c + l, c + r) *max_element(c + l, c + r) 配列の中のmin-max
// int dx[8]={1,1,0,-1,-1,-1,0,1};
// int dy[8]={0,1,1,1,0,-1,-1,-1};
// int dx[4]={1,0,-1,0};
// int dy[4]={0,1,0,-1};
// ~ は、-1の時だけfalse

int a[3010];
vector<ll> p(3010);

const int mod = 998244353;

int main () {

    int n,s;cin>>n>>s;

    rep(i,n) cin>>a[i];

    ll ans=0;

    rep(i,n) {
        vector<ll> q(3010);
        p[0]++;
        rep(j,s+1) {
            q[j]=(q[j]+p[j])%mod;
            if (j+a[i]<=s) {
                q[j+a[i]]=(q[j+a[i]]+p[j])%mod;
            }
        }
        ans=(ans+q[s])%mod;
        p=q;
    }

    cout<<ans<<endl;


}