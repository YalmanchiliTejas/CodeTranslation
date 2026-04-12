#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <math.h>
#include <complex>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <unordered_map>
#include <set>
#include <bitset>
#include <functional>
#include <assert.h>
using ll=long long;
#define int ll
#define rng(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,b) rng(i,0,b)
#define gnr(i,a,b) for(int i=int(b)-1;i>=int(a);i--)
#define per(i,b) gnr(i,0,b)
#define eb emplace_back
#define all(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
#define fi first
#define se second
const int INF = 1e15;
using namespace std;

template<class T> using vc=vector<T>;
template<class T> using vvc=vc<vc<T>>;

using pi=pair<int,int>;
using vi=vc<int>;

template<class T>
inline bool chmax(T &a,T b){if(a<b){a=b;return true;}return false;}
template<class T>
inline bool chmin(T &a,T b){if(a>b){a=b;return true;}return false;}

int d[55];
int dfs(int n,int pos){
    if(n==0) return 1;
    else{
        if(pos==1) return 0;
        else if(pos<=d[n-1]+1){
            return dfs(n-1,pos-1);
        }
        else if(pos==d[n-1]+2){
            return dfs(n-1,d[n-1])+1;
        }
        else if(pos<d[n-1]*2+3){
            return dfs(n-1,d[n-1])+dfs(n-1,pos-d[n-1]-2)+1;
        }
        else return dfs(n-1,d[n-1])*2+1;
    }
}

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout<<fixed<<setprecision(20);

    int N,X; cin >> N >> X;
    rep(i,N+1){
        if(!i) d[0]=1;
        else d[i]=d[i-1]*2+3;
    }
    cout << dfs(N,X) << endl;
}