//小数点以下　cout << fixed << setprecision(10) << num << endl;
//桁数はlog10(mid)でやれ　log(mid)/log(10)はWA
//long*long<0で判定するな
//開区間と閉区間
//アルファベットが何番目かは x=s[i]-'a'
//bfsはmain()内で　rep(i,h)rep(j,w)rep(i,4)でバグ
//切り上げ：(a+(b-1))/b
//32bit以上は 1ull<<j
// map 初期値0 for(auto itr=mp.begin();itr!=mp.end();++itr) itr->fi itr->se で全探索
// for(auto u:mp) u.fi u.se も可能
//n個のgcd,lcmは一つずつみて更新していく
//大きな数を扱うときは素因数分解した形で持っておく
// (l/a[i]) = l*powmod(a[i],MOD-2)%MOD;
//auto itr=lower_bound(ALL(a),key) a[itr-a.begin()]
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <queue>
#include <stack>
#include <tuple>
#include <cmath>
#include <iomanip>
#include <map>
#include <stdio.h>
#include <cstring> //memset(dp,0,sizeof(dp))
#include <functional> //operator[]
#define ll long long
#define rep(i,n) for(int i=0;i<(n);i++)
#define rrep(i,n) for(int i=n-1;i>=0;i--)
#define fi first
#define se second
#define pb push_back
#define ALL(a) (a).begin(),(a).end()
using namespace std;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
typedef pair<int,int> P;
typedef pair<ll,ll> Pll;

const int MAX = 200200;
const int MOD = 1000000007;

ll fac[MAX],finv[MAX],inv[MAX];
void COMinit(){
    fac[0]=fac[1]=1;
    finv[0]=finv[1]=1;
    inv[1]=1;
    for(int i=2;i<MAX;i++){
        fac[i]=fac[i-1]*i % MOD;
        inv[i]=MOD-inv[MOD%i]*(MOD/i) % MOD;
        finv[i]=finv[i-1]*inv[i] % MOD;
    }
}
ll COM(int n,int k){
    if(n<k) return 0;
    if(n<0 || k<0) return 0;
    return fac[n]*(finv[k]*finv[n-k] % MOD) % MOD;
}
signed main(){
    COMinit();
    ll n,m,k; cin >> n >> m >> k;
    ll sum=0;
    for(ll i=0;i<m;i++){
        ll res1=(i*(i+1)/2+(m-i)*(m-i-1)/2)%MOD;
        res1*=n; res1%=MOD;
        for(ll j=0;j<n;j++){
            ll res2=(j*(j+1)/2+(n-j)*(n-j-1)/2)%MOD;
            res2*=m; res2%=MOD;
            sum+=res1+res2;
            sum%=MOD;
        }
    }
    sum*=COM(n*m-2,k-2);
    sum%=MOD;
    if(sum%2==0) sum/=2;
    else{
        sum+=MOD;
        sum/=2;
        sum%=MOD;
    }
    cout << sum << endl;
}
