#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, k, n) for (int i = k; i < (int)(n); i++)
#define repd(i, n) for (int i = n-1; i >= 0; i--)
#define rrepd(i, k, n) for (int i = n-1; i >= (int)(k); i--)
#define all(x) (x).begin(),(x).end()
#define chmax(x,y) x=max(x,y)
#define chmin(x,y) x=min(x,y)
#define F first //pairの一つ目の要素
#define S second //pairの二つ目の要素
#define PB push_back //挿入
#define MP make_pair //pairのコンストラクタ
//V,Pは大文字i,l,bは小文字
using ll = long long;
using Vi = vector<int>;
using VVi = vector<Vi>;
using Vl = vector<ll>;
using VVl = vector<Vl>;
using Vb = vector<bool>;
using VVb = vector<Vb>;
using P = pair<int,int>;
using Pll = pair<ll, ll>;
const ll mod = 1000000007;
const ll inf = 1000000000000;//10の12乗

int main() {
    ll n,x,m;
    cin >> n >> x >> m;
    ll xx=x;
    vector<ll> v(m+10,-1);
    ll bgn=-1,syu=-1;
    rep(i,m+2){
        if(v[x]==-1) v[x]=i;
        else{
            bgn=v[x];
            syu=i-v[x];
            break;
        }
        x=(x*x)%m;
    }
    ll ans=0;
    Vl vf(1000000);
    if(bgn+syu>=n){
        rep(i,n){
            ans+=xx;
            xx*=xx;
            xx%=m;
        }
        cout << ans << endl;
        return 0;
    }
    vf[0]=xx;
    rep(i,1000000){
        vf[i+1]=(vf[i]*vf[i])%m;
    }
    rep(i,bgn){
        ans+=vf[i];
    }
    ll sum=0;

    rep(i,syu){
        sum+=vf[bgn+i];
    }
    ll nn=n-bgn;
    ans+=sum*(nn/syu);
    rep(i,nn%syu){
        ans+=vf[i+bgn];
    }
    cout << ans << endl;

}