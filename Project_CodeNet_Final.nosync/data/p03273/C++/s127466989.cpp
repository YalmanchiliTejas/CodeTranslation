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
    int H,W; cin>>H>>W;
    char a[H][W]; REP(i,H) REP(j,W) cin>>a[i][j];
    vector<int> h,w;
    REP(i,H) {
        bool flag = true;
        REP(j,W) {
            if (a[i][j]=='#') {
                flag = false;
                break;
            }
        }
        if (flag) h.push_back(i);
    }
    REP(i,W) {
        bool flag = true;
        REP(j,H) {
            if (a[j][i]=='#') {
                flag = false;
                break;
            }
        }
        if (flag) w.push_back(i);
    }
    REP(i,h.size()) cerr<<h[i]<<" ";
    cerr<<endl;
    REP(i,w.size()) cerr<<w[i]<<" ";
    cerr<<endl;
    REP(i,H) {
        bool flag = true;
        REP(k,h.size()) {
            if (i==h[k]) {
                flag = false;
                break;
            }
        }
        if (flag) {
            REP(j,W) {
                flag = true;
                REP(l,w.size()) {
                    if (j==w[l]) {
                        flag = false;
                        break;
                    }
                }
                if (flag) cout<<a[i][j];
            }
            cout<<endl;
        }
    }
}
