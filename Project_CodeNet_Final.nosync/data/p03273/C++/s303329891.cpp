#include<bits/stdc++.h>
using namespace std;
typedef  long long ll;
template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
//自作関数
template<class T> ll llpow(T x,T n){ll ans=1;while(n--){ans*=x;}return ans;}

#define rep(i,n) for(ll i=0;i<(ll)n;i++)
#define rep2(i, begin_i, end_i) for (ll i = (ll)begin_i; i < (ll)end_i; i++)

long long INF = 1LL<<60;
int n;
int main(){
    ll h,w;
    cin>>h>>w;
    char a[h][w];
    rep(i,h){
        rep(j,w){
            cin>>a[i][j];
        }
    }

    bool column[w];
    bool row[h];
    rep(i,w)column[i]=true;
    rep(i,h)row[i]=true;
    rep(i,h)rep(j,w)if(a[i][j]=='#')row[i]=false;

    rep(i,w)rep(j,h)if(a[j][i]=='#')column[i]=false;

    rep(i,h){
        rep(j,w){
            if((!row[i])&&(!column[j])){
                cout<<a[i][j];
            }
            if((!row[i])&&(j==w-1)){
                cout<<endl;
            }
        }
    }
    return 0;
}


