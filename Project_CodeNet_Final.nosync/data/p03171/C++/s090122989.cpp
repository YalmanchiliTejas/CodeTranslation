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
#define S second　//pairの二つ目の要素

int n;
vector<ll> a;
ll memo[3000][3000];
int flag[3000][3000]={};

ll dp(int ifir, int ibak){ // X-Y
    if(flag[ifir][ibak]) return memo[ifir][ibak];
    flag[ifir][ibak]=1;
    ll ret;
    if(ifir==ibak) {
        if((n+ifir+ibak)%2==1) ret=a[ifir];
        else ret=-a[ifir];
    }
    else{
        if((n+ifir+ibak)%2==1){
            ret=max(a[ifir]+dp(ifir+1,ibak),a[ibak]+dp(ifir,ibak-1));
        }
        else{
            ret=min(-a[ifir]+dp(ifir+1,ibak),-a[ibak]+dp(ifir,ibak-1));
        }
    }
    memo[ifir][ibak]=ret;
    return ret;
}

int main(){
    cin>>n;
    a.resize(n);
    rep(i,n) cin>>a[i];
    cout<<dp(0,n-1)<<endl;
    return 0;
}