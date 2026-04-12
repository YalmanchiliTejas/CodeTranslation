#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) for(int i=0;i<(n);++i)
#define REPR(i,n) for(int i=n;i>=0;i--)
#define ALL(v) (v.begin(),v.end())
#define COUT(x) cout<<(x)<<'\n'

int main(){
    int h,w;
    cin >> h >> w;
    string sum[h];
    REP(i,h)cin >> sum[i];
    int count=0;
    REP(i,h){
        REP(j,w){
            if(sum[i][j]=='#')count++;
        }
    }
    if(count==(h+w-1))COUT("Possible");
    else COUT("Impossible");
    return 0;
}