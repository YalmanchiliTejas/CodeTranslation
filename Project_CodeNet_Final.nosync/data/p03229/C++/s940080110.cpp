#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<ll,ll> l_l;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
const int INF=1001001000;
const int mINF=-1001001000;
const ll LINF=1010010010010010000;
template<class T> inline bool chmin(T& a, T b) {
if (a > b) {
a = b;
return true;
}
return false;
}
template<class T> inline bool chmax(T& a, T b) {
if (a < b) {
a = b;
return true;
}
return false;
}
//グリッド：（典型）dp,dfs,bfs,最短経路,その他
int main(){
    int n;cin >> n;
    vl a(n);
    rep(i,n) cin >> a[i];
    sort(a.begin(),a.end());
    ll ans1,ans2;
    {
        ans1=0;
        vl kei;
        kei.push_back(-1);
        if(n%2==0){
            for(int i=1;i<n-1;i++){
                if(i%2==1) kei.push_back(2);
                else kei.push_back(-2);
            }
            kei.push_back(1);
        }
        else{
            for(int i=1;i<n-1;i++){
                if(i%2==1) kei.push_back(2);
                else kei.push_back(-2);
            }
            kei.push_back(-1);
        }
        sort(kei.begin(),kei.end());
        rep(i,n){
            ans1+=kei[i]*a[i];
        }
    }
    {
        ans2=0;
        vl kei;
        kei.push_back(1);
        if(n%2==0){
            for(int i=1;i<n-1;i++){
                if(i%2==1) kei.push_back(-2);
                else kei.push_back(2);
            }
            kei.push_back(-1);
        }
        else{
            for(int i=1;i<n-1;i++){
                if(i%2==1) kei.push_back(-2);
                else kei.push_back(2);
            }
            kei.push_back(1);
        }
        sort(kei.begin(),kei.end());
        rep(i,n){
            ans2+=kei[i]*a[i];
        }
    }
    if(ans1>ans2){
        cout << ans1 << endl;
    }
    else cout << ans2 << endl;
    return 0;
}