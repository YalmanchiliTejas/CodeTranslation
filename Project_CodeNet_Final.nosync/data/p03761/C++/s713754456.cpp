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

int n;

int main(){
    int n;
    cin >> n;
    vector<string> s(n);
    REP(i,n){
        cin >> s[i];
    }
    vector<vector<int>> c(26,vector<int>(n,0));
    REP(i,n){
        REP(j,s[i].size()){
            int temp = s[i][j]-'a';
            c[temp][i]++;
        }
    }
    vector<int> cnt(26);
    REP(i,26){
        cnt[i] = *min_element(all(c[i]));
    }
    string res = "";
    REP(i,26){
        REP(j,cnt[i])res.push_back((char)i+'a');
    }
    put(res);
    return 0;
}
