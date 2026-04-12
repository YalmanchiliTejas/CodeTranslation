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
#include <cstring> //memset(dp,0,sizeof(dp))
#include <functional>
#define ll long long
#define rep(i,n) for(int i=0;i<(n);i++)
#define repp(i,n) for(int i=n-1;i>=0;i--)
#define fi first
#define se second
#define pb push_back
#define ppb pop_back()
#define ALL(a) (a).begin(),(a).end()
using namespace std;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
typedef pair<int,int> P;
typedef pair<ll,ll> Pll;

signed main(){
    int h,w; cin >> h >> w;
    char c[h][w];
    bool ok[h][w];
    rep(i,h){
        bool fl=1;
        rep(j,w){
            cin >> c[i][j];
            if(c[i][j]=='#') fl=0;
        }
        if(fl){
            rep(j,w)ok[i][j]=0;
        }else{
            rep(j,w)ok[i][j]=1;
        }
    }
    rep(j,w){
        bool fl=1;
        rep(i,h){
            if(c[i][j]=='#') fl=0;
        }
        if(fl){
            rep(i,h)ok[i][j]=0;
        }
    }
    rep(i,h){
        bool fl=0;
        rep(j,w){
            if(ok[i][j]){
                fl=1;
                cout<<c[i][j];
            }
        }
        if(fl)cout << endl;
    }
}
