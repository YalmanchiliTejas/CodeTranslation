#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(n);i++)

typedef long long ll;

#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=(ll)(b);i--)
//定数
#define INF 1000000000 //10^9:極めて大きい値,∞
//略記
#define PB push_back //vectorヘの挿入
#define MP make_pair //pairのコンストラクタ
#define F first //pairの一つ目の要素
#define S second //pairの二つ目の要素

int main(){
    ll N,X,M; // N:個数
    cin>>N>>X>>M;
    map<ll,int> ma;
    vector<ll> v;
    ll a=X;
    int i=0;
    while(!ma.count(a)){
        v.push_back(a);
        ma[a]=i++;
        a=(a*a)%M;
    }
    v.push_back(a); // 忘れずに！
    ll c=i-ma[a]; // 循環周期
    ll s=ma[a]; // 循環スタート
    vector<ll> cv(c+1);
    cv[0]=0;
    for(int i=1;i<=c;i++) cv[i]=cv[i-1]+v[i+s]; // 巡回内累積
    ll ans=0;
    if(N<=s){ // 循環前
        rep(i,N) ans+=v[i];
    }
    else{
        for(int i=0;i<=s;i++) ans+=v[i]; // スタート位置まで
        ans+=(N-1-s)/c*cv[c];
        ans+=cv[(N-1-s)%c];
    }
    cout<<ans<<endl;
    return 0;
}