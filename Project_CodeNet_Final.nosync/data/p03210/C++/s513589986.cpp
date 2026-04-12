#include<bits/stdc++.h>
using namespace std;
#define ll long long                                    // long long省略
#define pb push_back                                    // push_back省略
#define mp make_pair                                    // make_pair省略
#define fi first                                        // first省略
#define se second                                       // second省略
#define itn int                                         // int誤字保険
#define count cout                                      // cout誤字保険
#define vecotr vector                                   // vector誤字保険
#define ednl endl                                       // endl誤字保険
#define opt() cin.tie(0); ios::sync_with_stdio(false)   // 入出力速度改善

#define rep(i,l,r) for(ll i=(l);i<(r);i++)               // 範囲[l, r)で刻み1のfor文(順方向)
#define repp(i,l,r,k) for(ll i=(l);i<(r);i+=(k))         // 範囲[l, r)で刻みkのfor文(順方向)
#define rrep(i,l,r) for(ll i=(r-1);i>=(l);i--)           // 範囲[l, r)で刻み1のfor文(逆方向)
#define rrepp(i,l,r,k) for(ll i=(r-1);i>=(l);i-=(k))     // 範囲[l, r)で刻みkのfor文(逆方向)
#define all(x) (x).begin(), (x).end()                   // vectorのポインタ位置指定用
#define max(p,q)((p)>(q)?(p):(q))                       // max拡張
#define min(p,q)((p)<(q)?(p):(q))                       // min拡張
#define bit(n,m)(((n)>>(m))&1)                          // 変数nのm番目のbitを取り出す

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int dy[]={0, 1, 0, -1};                                 // 4方向近傍
int dx[]={1, 0, -1, 0};                                 // 4方向近傍

int main(){
    ll n,a,b;cin>>n>>a>>b;
    cout << (n==3||n==5||n==7?"YES":"NO") << endl;
}
