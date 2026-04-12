#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define FOR(i,n,m) for(int i=(int)(n); i<=(int)(m); i++)
#define RFOR(i,n,m) for(int i=(int)(n); i>=(int)(m); i--)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define RITR(x,c) for(__typeof(c.rbegin()) x=c.rbegin();x!=c.rend();x++)
#define setp(n) fixed << setprecision(n)

template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }

#define ll long long
#define vll vector<ll>
#define vi vector<int>
#define pll pair<ll,ll>
#define pi pair<int,int>

#define all(a) (a.begin()),(a.end())
#define rall(a) (a.rbegin()),(a.rend())
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define ins insert

using namespace std;

// Time: 10:55:17

// まず，A+Bの操作が2Cの操作と等価なのでchminを取っておく(操作の等価性)
// ちょうど作る場合は算数でいいのだが，ちょうどでないので
// 今回は全探索をする必要があった．(本当は二分探索でいけるはず)

// 一番厄介なものを決めうつと嬉しい例(Cのものが厄介なので固定した)

//-------------------------------------------------

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int A,B,C,X,Y; cin>>A>>B>>C>>X>>Y;
    // C*=2;s
    // chmin(C,A+B);
    // ll ans=(ll)1e15;
    auto f = [&](int n){
        ll ret=0;
        ret+=(ll)n*2*C;
        int x=max(X-n,0),y=max(Y-n,0);
        ret+=(ll)x*A+(ll)y*B;
        return ret;
    };
    int l=-1,r=max(X,Y);
    while(r-l>1){
        int c=(l+r)/2;
        if (f(c+1)-f(c)<=0) l=c;
        else r=c;
    }
    ll ans=f(l+1);
    // FOR(i,min(X,Y),max(X,Y)){
    //     ll cand=0;
    //     cand+=(ll)i*C;
    //     int x=X-i,y=Y-i;
    //     chmax(x,0); chmax(y,0);
    //     cand+=(ll)x*A;
    //     cand+=(ll)y*B;
    //     chmin(ans,cand);
    // }
    cout<<ans<<"\n";
    return 0;
}
