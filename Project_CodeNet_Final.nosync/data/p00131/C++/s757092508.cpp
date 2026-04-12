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
    int to, cost;
    Edge(int to, int cost): to(to), cost(cost) {}
};

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<Edge>> AdjList;
AdjList graph;

const int INF = 100000000;
struct UF {
    vi e;
    UF(int n) : e(n, -1) {}
    bool same_set(int a, int b) { return find(a) == find(b); }
    int size(int x) { return -e[find(x)]; }
    int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }

    void join(int a, int b) {
        a = find(a), b = find(b);
        if(a == b) return;
        if(e[a] > e[b]) swap(a, b);
        e[a] += e[b]; e[b] = a;
    }
};
int main() {
    //cout << fixed << setprecision(15);

    int n; cin >> n;
    int cnt=0;
    while(n--) {
        vector<vector<int>> v(10);

        for(int i=0; i<10; ++i){
            for(int j=0; j<10; ++j){
                int a; cin >> a;
                v[i].push_back(a);
            }
        }

        bool f = false;
        for(int bit=0; bit<(1<<10); ++bit){
            int arr[15][15]={0};

            int ans[10][10]={0};
            for(int i=0; i<10; ++i){
                if(bit >> i & 1){
                    ans[0][i]=1;
                    if(i==0){
                        arr[0][0] ^= 1;
                        arr[1][0] ^= 1;
                        arr[0][1] ^= 1;
                    }else if(i==9){
                        arr[0][i] ^= 1;
                        arr[1][i] ^= 1;
                        arr[0][i-1] ^= 1;
                    }else{
                        arr[0][i] ^= 1;
                        arr[0][i-1] ^= 1;
                        arr[0][i+1] ^= 1;
                        arr[1][i] ^= 1;
                    }
                }
            }

            for(int i=1; i<10; ++i){
                for(int j=0; j<10; ++j){
                    if((arr[i-1][j] == 0 && v[i-1][j]==1) || (arr[i-1][j]==1 && v[i-1][j]==0)){
                        ans[i][j]=1;
                        if(j==0){
                            arr[i][j] ^= 1;
                            arr[i+1][j] ^= 1;
                            arr[i][j+1] ^= 1;
                            arr[i-1][j] ^= 1;
                        }else if(j==9){
                            arr[i][j] ^= 1;
                            arr[i-1][j] ^= 1;
                            arr[i+1][j] ^= 1;
                            arr[i][j-1] ^= 1;
                        }else{
                            arr[i][j] ^= 1;
                            arr[i][j-1] ^= 1;
                            arr[i][j+1] ^= 1;
                            arr[i+1][j] ^= 1;
                            arr[i-1][j] ^= 1;
                        }
                    }
                }
            }
            bool d = true;
            for(int i=0; i<10; ++i){
                for(int j=0; j<10; ++j){
                    if(arr[i][j]!=v[i][j]) d= false;
                }
            }
            if(!d) continue;
            for(int i=0; i<10; ++i){
                for(int j=0; j<10; ++j){
                    if(j) cout << " ";
                    cout << ans[i][j];
                }
                cout << endl;
            }
            break;
        }
    }
    return 0;
}
