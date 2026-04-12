#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef tuple<ll,ll,ll> T;
const long long INF = 1LL<<60;
// const int MOD = 1000000000+7;
#define rev(s) (string((s).rbegin(), (s).rend()))
// cout << fixed << setprecision(10) << ans << endl; 有効桁数指定
// *min_element(c + l, c + r) *max_element(c + l, c + r) 配列の中のmin-max
// int dx[8]={1,1,0,-1,-1,-1,0,1};
// int dy[8]={0,1,1,1,0,-1,-1,-1};
// int dx[4]={1,0,-1,0};
// int dy[4]={0,1,0,-1};
// ~ は、-1の時だけfalse

const int mod = 998244353;

vector<int> cnt(3010);
int a[3010];

int main () {

    int n,s;cin>>n>>s;

    rep(i,n) cin>>a[i];

    ll ans=0;


    rep(i,n) {
        cnt[0]++;
        vector<int> cnt_n(3010);
        rep(j,s+1) {
            cnt_n[j]=(cnt_n[j]+cnt[j])%mod;
            if (j+a[i]<=s) {
                cnt_n[j+a[i]]=(cnt_n[j+a[i]]+cnt[j])%mod;
            }
        }
        cnt=cnt_n;
        ans=(ans+cnt[s])%mod;
    }

    cout<<ans<<endl;

}