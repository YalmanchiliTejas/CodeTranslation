#include <iostream>
#include <algorithm>
#include <utility>
#include <string>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <map>
#include <math.h>
#include <string.h>
#include <iomanip>
#include <numeric>
#include <cstdlib>
#include <cstdint>
#include <cmath>
#include <functional>
#include <limits>

using namespace std;

using ll = long long;
using pll = pair<ll, ll>;
using vl = vector<ll>;
using vll = vector<vl>;
using vpll = vector<pll>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = ((int)(n)-1); i >= 0; i--)
#define Rep(i, n) for (long long i = 0; i< (long long)(n); i++)
#define RRep(i,n) for (long long i = ((long long)(n)-1); i>=0; i--)
#define all(v) (v).begin(),(v).end()

struct Edge{
    int to;
    int weight;
    Edge(int t, int w) : to(t), weight(w){ }
};

struct edge{
    int from;
    int to;
    int weight;
    edge(int f,int t,int w) : from(f), to(t), weight(w){ }
};

using Graph = vector<vector<Edge>>;
using graph = vector<vector<int>>;
using edges = vector<edge>;

template <class T>
inline bool chmin(T &a, T b){
    if (a > b){
        a = b;
        return true;
    }
    return false;
}

template <class T>
inline bool chmax(T &a, T b){
    if (a < b){
        a = b;
        return true;
    }
    return false;
}

template <class T>
T gcd(T a, T b){
    if( b==0 ) return a;
    return gcd(b, a%b);
}

template <class T>
T lcm(T a, T b){
    return (a*b)/gcd(a,b);
}

int INF = 1e9+7;

vector<int> dx = {-1,0,1,0};
vector<int> dy = {0,-1,0,1};

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int a,b,c;
    cin >> a >> b >> c;
    int x,y;
    cin >> x >> y;
    int d = c*2;
    int ans = INF;
    rep(i,max(x,y)+1){
        if(x>max(x,y)-i && y>max(x,y)-i){
            chmin(ans,(max(x,y)-i)*d+a*(x-max(x,y)+i)+b*(y-max(x,y)+i));
        }
        else if(x>max(x,y)-i){
            chmin(ans,(max(x,y)-i)*d+a*(x-max(x,y)+i));
        }
        else if(y>max(x,y)-i){
            chmin(ans,(max(x,y)-i)*d+b*(y-max(x,y)+i));
        }
        else{
            chmin(ans,max(x,y)*d);
        }
    }
    cout << ans << endl;
}