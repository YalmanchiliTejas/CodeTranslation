#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
using ll = long long;
const ll MOD = 998244353;
const int INF = 1001001001;
// const ll INF = 1000000000000000000LL;
  
int main() {
    ll n,x,m;
    cin >> n >> x >> m;
    ll xx = x;
    ll xxx = x;
    ll top;
    vector<int> id(m,-1);
    int len1 = 0;
    int len2 = 0;
    ll sum1 = 0;
    ll sum2 = 0;
    // ll before_x;
    while(1){
        if(id[x]!=-1) {
            top = x;
            break;
        }
        len1++;
        sum1+=x;
        id[x] = len1;
        // before_x = x;
        x = x*x%m;

    }
    // cout << x << endl; //重複した数
    // cout << len1 << endl;
    //重複した数が最初にあらわれるまでのsum
    while(1){
        if(xx==x) break;
        len2++;
        sum2+=xx;
        xx = xx*xx%m;
    }
    // cout << len2 << endl;
    // cout << sum1 << endl;
    // cout << sum2 << endl;
    ll a = sum2;//ループ検出前のsum
    ll b = sum1 - sum2; //ループのsum
    ll la = len2; //ループ検出前の数の個数
    ll lb = len1 - len2; //ループのなかの数の個数
    // cout << a << endl;
    // cout << b << endl;
    // cout << la << endl;
    // cout << lb << endl;
    //こたい
    ll ans=0;
    if(n<la){
        rep(i,n){
            ans+=xxx;
            xxx = xxx*xxx%m;
        }
        // cout << ans << endl;
        return 0;
    }
    n-=la;
    ans+=a;
    ll nn = n/lb; //ループの出現回数
    // cout << top << endl;
    n%=lb; //残り
    ans+=b*nn;
    // cout << n << endl;
    rep(i,n){
        ans+=top;
        top=top*top%m;
    }
    cout << ans << endl;
    return 0;
}