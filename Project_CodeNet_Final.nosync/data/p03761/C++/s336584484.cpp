#include<iostream>
#include<iomanip>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<bitset>
#include<queue>
#include<set>
#include<map>
using namespace std;

#define FOR(i,a,b) for (int i=(a);i<(b);++i)
#define ROF(i,b,a) for (int i=(b);i>(a);--i)
#define REP(i,n) FOR(i,0,n)
#define PER(i,n) ROF(i,n-1,-1)

typedef int i32;
typedef long long int i64;
typedef unsigned long long int ui64;
typedef float f32;
typedef double f64;
typedef long double f128;
typedef pair<int,int> Pi;

constexpr int INF = 1e9 + 7;
constexpr int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};

int main() {
    int n; cin>>n;
    string S[n];
    REP(i,n) cin>>S[i];
    map<char,int> m;
    REP(i,S[0].size()) m[S[0][i]]++;
    REP(i,n-1) {
        map<char,int> s;
        REP(j,S[i+1].size()) s[S[i+1][j]]++;
        for (auto &x: m) x.second = min(s[x.first],x.second);
    }
    for (auto x: m) REP(i,x.second) cout<<x.first;
}
