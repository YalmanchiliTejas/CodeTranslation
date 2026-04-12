#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll MOD=(ll)1e9+7;
//const ll MOD=(ll)998244353;
const ll INF=(ll)1e18+10;
const double PI = 2.0*acos(0);
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
int dy[]={-1,1,0,0};
int dx[]={0,0,-1,1};

void solve(int ca){
    int A,B,C,X,Y; cin>>A>>B>>C>>X>>Y;
    ll ans=INF;
    for (int i = 0; i <= 2*max(X, Y); i+=2) {
        ll tmp=C*i;
        //cout<<tmp<<endl;
        int a=max(0,X-i/2), b=max(0,Y-i/2);
        tmp+=a*A+b*B;
        //cout<<i<<" "<<tmp<<endl;
        chmin(ans,tmp);
    }
    cout<<ans<<endl;

}

//#define MULTI
int main() {
#ifdef MULTI
    int N; cin>>N;
    for (int i = 0; i < N; ++i) {
        solve(i+1);
    }
#else
    solve(0);
#endif
    return 0;
}
