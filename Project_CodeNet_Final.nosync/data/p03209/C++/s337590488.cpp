/// Containers Start
#include <algorithm>
#include <bitset>
#include <cstdlib>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>
#include <tuple>
/// C Header Files
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <math.h>
#include <stdio.h>
/// Containers End

using namespace std;

/// Math Start
#define PI acos(-1.0)
#define Pi 3.141592653589793
#define EPS (1e-7)
#define INF (0x3f3f3f3f)
#define MAX_V 100100
/// Math End

/// Extra Start
#define nn '\n'
#define pb push_back
#define ull unsigned long long
#define ll long long
#define MOD 1000000007
#define sz(a) int((a).size())
#define space " "
#define All(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
/// Extra End



#define rep(i, n) for (int i = 0; i < n; i++)
#define Cini(a)                                                                \
    int a;                                                                     \
    cin >> a;
#define Cinii(a, b)                                                            \
    int a, b;                                                                  \
    cin >> a >> b;
#define Ciniii(a, b, c)                                                        \
    int a, b, c;                                                               \
    cin >> a >> b >> c;
#define Cins(s)                                                                \
    string s;                                                                  \
    cin >> s;
#define Cinss(s1, s2)                                                          \
    string s1, s2;                                                             \
    cin >> s1 >> s2;
#define Cinc(c)                                                                \
    char c;                                                                    \
    cin >> c;
/// Functions End


/// Graph Start
struct edge {
    int from, to;
    long long cost;
};
/// Graph End

/// Debug Start
#define deb(x) cout << #x << ": " << x << endl
#define deb2(x, y) cout << #x << ": " << x << '\t' << #y << ": " << y << endl;
#define deb3(x, y, z)                                                          \
    cout << #x << ": " << x << '\t' << #y << ": " << y << '\t' << #z << ": "   \
         << z << endl;
/// Debug End

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

/**>>>>>>>>>>>>>>>>>>> END <<<<<<<<<<<<<<<<<<**/

/// template

long long p[50+5],len[50+5],n,x;

long long dp(long long n,long long x){
    // deb2(n,x);
    x = min(x,len[n]);
    if(n==0 && x>=1) return 1; 
    if(x<=1){
        return 0;
    }else if(x<=len[n-1]+1LL){
        return dp(n-1,max(x-1,1LL));
    }else if(x==len[n-1]+2LL){
        return dp(n-1,max(x-1,1LL)) + 1LL;
    }else if(x<=2LL*len[n-1]+2){
        return (dp(n-1,max(x-1,1LL))+1LL) + dp(n-1,max(x-len[n-1]-2LL,1LL));
    }else{
        return dp(n-1,max(x-1,1LL)) * 2 + 1;
    }
}

int main(void) {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> x;
    len[0] = 1;
    p[0] = 1;
    rep(i,51) len[i+1] = len[i] * 2 + 3;
    rep(i,51) p[i+1] = p[i] * 2 + 1;
    long long ans = 0;
    cout << dp(n,x) << nn;
    return 0;
}