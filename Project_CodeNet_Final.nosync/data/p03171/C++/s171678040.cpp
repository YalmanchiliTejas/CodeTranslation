    /* @Author: Shubham Anand */

#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <limits>
#include <chrono>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>

#define FILEIN          freopen("input.txt", "r", stdin)
#define FILEOUT         freopen("output.txt", "w", stdout)
#define FASTIO          std::ios_base::sync_with_stdio(0); std::cin.tie(NULL); std::cout.tie(NULL)
#define PAUSE           while(1){}
#define NEWLINE         std::cout << "\n"
#define EDGES           std::unordered_map<std::pair<int,int>,int>
#define PB(N)           push_back(N)

/* Constants */
const unsigned int MODULO = 1e9+7;
const unsigned int INF = std::numeric_limits<int>::max();
const int NINF = std::numeric_limits<int>::min();

/* Input Output */
template <class T> void write(const T &a, char del='\n')        { if(del=='~')std::cout<<a; else std::cout<<a<<del; }
template <class T> void line(const T &w)                        { for(int i=0;i<(w+1)/2;i++)write('_','_');NEWLINE; }
template <class T> void read(T &a)                              { std::cin >> a; }

/* Modular Ops */
template <class T> T add(T a, T b, T m) { a=a%m; b=b%m; return (a+b)%m; }
template <class T> T mul(T a, T b, T m) { a=a%m; b=b%m; return (a*b)%m; }

/* Basic Algorithms */
template <class T> T gcd(T a, T b)      { if(b>a){return gcd(b,a);} if(b==0){return a;} return gcd(b, a%b); }
template <class T> T bexp(T a, T b, T m){ if(b==1){return a;}if(b&1){return mul(a,bexp(a,b-1,m),m);}T c=bexp(a,b/2,m); return mul(c,c,m);}
template <class T> T inv(T a, T m)      { return bexp(a,m-2,m); }

/* Commonly used data structures */
namespace ds {
    template<class T> struct Point{ T x,y,z; Point(T _x=0,T _y=0,T _z=0):x(_x), y(_y), z(_z){}; };
    template<class T> struct Graph{ std::vector<T> *adj; Graph(T n){adj=new std::vector<T>[n];} void add(T u, T v, bool d=0){adj[u].PB(v);if(!d){adj[v].PB(u);}} void w_add(T u, T v, T w, bool d=0){adj[u].PB(std::make_pair(v,w)); if (!d){adj[v].PB(std::make_pair(u,w));}}};
}

/* Function to calculate runtime */
void time(void func()) {
    std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
    start = std::chrono::high_resolution_clock::now();
    func();
    end = std::chrono::high_resolution_clock::now();
    long long elapsed_time = std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count();
    std::cout << "\tElapsed Time: " << elapsed_time << "ms\n";
}

/* Declare any global objects here */
typedef long long ull;
ull dp[3001][3001];
/************** END ****************/

void solve() {

    int N;
    std::cin >> N;

    ull val[N];
    for (int i=0; i<N; i++) { std::cin >> val[i]; }

    for (int L=N; ~L; L--) {
        for (int R=L; R<N; R++) {
            if (L==R) { dp[L][R] = val[L]; }
            else { dp[L][R] = std::max(val[L] - dp[L+1][R], val[R] - dp[L][R-1]); }
        }
    }

    write(dp[0][N-1]);

}

signed main() {

    // FILEIN; 
    // FILEOUT;
    FASTIO;

    int T = 1;
    // Uncomment to read testcases
    // read(T);
    
    while (T--) {
        // time(solve);
        solve();
    }

    return 0;
}