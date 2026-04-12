#include <vector>
#include <list>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <queue>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <fstream>
#include <cstdio>
#include <climits>
#include <complex>
#include <cstdint>
#include <tuple>

#define M_PI       3.14159265358979323846

using namespace std;

//conversion
//------------------------------------------
inline int toInt(string s) { int v; istringstream sin(s); sin >> v; return v; }
template<class T> inline string toString(T x) { ostringstream sout; sout << x; return sout.str(); }
inline int readInt() { int x; scanf("%d", &x); return x; }

//typedef
//------------------------------------------
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef pair<int, PII> TIII;
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<LL> VLL;
typedef vector<VLL> VVLL;

//container util

//------------------------------------------
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define MP make_pair
#define SZ(a) int((a).size())
#define SQ(a) ((a)*(a))
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())

//repetition
//------------------------------------------
#define FOR(i,s,n) for(int i=s;i<(int)n;++i)
#define REP(i,n) FOR(i,0,n)
#define MOD 1000000007

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()


struct Edge {
    int to, cost, nm;
    Edge(int to, int cost, int nm): to(to), cost(cost), nm(nm) {}
};

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<Edge>> AdjList;
AdjList graph;
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)
const int INF = 100000000;

int GCD(int a, int b){
    if(a < b) swap(a, b);
    if(b == 0) return a;
    return GCD(b, a%b);
}

bool cmp(const pii& a, const pii& b){
    if(a.first == b.first){
        return a.second < b.second;
    }
    return a.first < b.first;
}

int main() {
    //cout << fixed << setprecision(15);

    int n;
    while(cin >> n, n){
        int arr[20][20];
        REP(i,20) REP(j,20) arr[i][j]=0;
        arr[n/2+1][n/2] = 1;


        int t = 2;
        int y = n/2 + 1;
        int x = n/2;
        while(t!=n*n+1){
            y++; x++;

            if(y>=n){
                y=0;
            }
            if(x>=n){
                x=0;
            }

            if(arr[y][x] == 0){
                arr[y][x] = t;
                t++;
            }else{
                y++;
                x--;
                if(y>=n){
                    y=0;
                }
                if(x>=n){
                    x=0;
                }
                if(x<0) x = n-1;
                arr[y][x] = t;
                t++;
            }

        }

        for(int i=0; i<n; ++i){
            for(int j=0; j<n; ++j){
                cout << right << setw(4) << arr[i][j];
            }
            cout << endl;
        }
    }
    return 0;
}
