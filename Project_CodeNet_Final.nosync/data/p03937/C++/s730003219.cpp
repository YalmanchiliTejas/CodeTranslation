#include "bits/stdc++.h"
using namespace std;
#define Rep(i,n) for(int i=0;i<(int)(n);i++)
#define For(i,n1,n2) for(int i=(int)(n1);i<(int)(n2);i++)
#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define RREP(i,n) for(ll i=((ll)(n)-1);i>=0;i--)
#define FOR(i,n1,n2) for(ll i=(ll)(n1);i<(ll)(n2);i++)
#define put(a) cout<<a<<"\n"
#define all(a)  (a).begin(),(a).end()
#define SORT(a) sort((a).begin(),(a).end())
#define oorret 0
#define oor(x) [&](){try{x;} catch(const out_of_range& oor){return oorret;} return x;}()
#define SZ(x) ((ll)(x).size())
typedef long long ll;
typedef pair<int, int> P;
template<typename T1,typename T2> inline bool chmin(T1 &a,T2 b){if(a>b){a=b;return 1;}return 0;}
template<typename T1,typename T2> inline bool chmax(T1 &a,T2 b){if(a<b){a=b;return 1;}return 0;}

char a[10][10];

int main(){
    int h,w;
    cin >> h >> w;
    REP(i,h){
        REP(j,w){
            cin >> a[i][j];
        }
    }
    bool flag = true;
    REP(i,h-1){
        REP(j,w-1){
            if(a[i+1][j]=='#'&&a[i][j+1]=='#')flag = false;
        }
    }
    if(flag){
        put("Possible");
    }else{
        put("Impossible");
    }
    return 0;
}
