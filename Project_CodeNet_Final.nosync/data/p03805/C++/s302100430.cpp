#include "bits/stdc++.h"
using namespace std;

#define Rep(i,n) for(int i=0;i<(n);i++)
#define For(i,n1,n2) for(int i=(n1);i<(n2);i++)
#define REP(i,n) for(ll i=0;i<(n);i++)
#define RREP(i,n) for(ll i=(n-1);i>=0;i--)
#define FOR(i,n1,n2) for(ll i=(n1);i<(n2);i++)
#define put(a) cout<<(a)<<"\n";
#define all(a)  (a).begin(),(a).end();
#define SORT(a) sort((a).begin(),(a).end())
#define TDARRAY(int,a,n,m) vector<vector<int>> a(n,vector<int>(m,0));
#define oorret 0
#define oor(x) [&](){try{x;} catch(const out_of_range& oor){return oorret;} return x;}()

typedef long long ll;
typedef pair<int, int> P;
template<typename T1,typename T2> inline bool chmin(T1 &a,T2 b){if(a>b){a=b;return 1;}return 0;}
template<typename T1,typename T2> inline bool chmax(T1 &a,T2 b){if(a<b){a=b;return 1;}return 0;}

int n,m;
const int MAXN = 8;
bool e[MAXN][MAXN];
int main(){
    cin >> n >> m;
    vector<int> a(m);
    vector<int> b(m);
    //vector<vector<int>> e(n);
    
    REP(i,n){
        REP(j,n){
            e[i][j] = false;
        }
    }
    REP(i,m){
        cin >> a[i] >> b[i];
        a[i]--;
        b[i]--;
        e[a[i]][b[i]] = true;
        e[b[i]][a[i]] = true;
    }
    vector<int> v(n-1);
    iota(v.begin(), v.end(), 1);
    int res = 0;
    do {
        bool flag = true;
        if(!e[0][v[0]]){
            flag = false;
        }
        REP(i,n-2){
            if(!e[v[i]][v[i+1]]){
                flag = false;
            }
        }
        if(flag){
            res++;
        }
    } while( next_permutation(v.begin(), v.end()) );     // 次の順列を生成
    put(res);
    return 0;
}
