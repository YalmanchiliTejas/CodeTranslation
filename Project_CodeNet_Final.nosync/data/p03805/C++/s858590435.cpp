#include<iostream>
#include<cmath>
#include<vector>
#include<set>
#include<algorithm>
#include<tuple>
#include<utility>
#include<cctype>
#include<climits>
#include<map>
#include<queue>
#include<functional>

using namespace std;

#define REP(i,a,n) for(int i=a;i<n;++i)
#define REPL(i,a,n) for(ll i=a;i<n;++i)
#define RUP(a,b) ((a+b-1)/(b))
#define ENT "\n"
#define SRTVG(v) sort(v.begin(),v.end(),greater<>())
#define SRTV(v) sort(v.begin(),v.end())
#define SRTAG(a,n) sort(a,a+n,greater<>())
#define MOD 1000000007

typedef long long ll;
typedef tuple<int,int,bool> Tb;
typedef pair<ll,ll> Pi;
typedef map<string,int> si;

template<class T> void chmax(T& a, T b) {if(a < b){a=b;}}
template<class T> void chmin(T& a, T b) {if(a > b){a=b;}}
template<class T> void YesNo(T& a) {if(a){cout << "Yes" << ENT;}else{cout << "No" << ENT;}}
template<class T> void YESNO(T& a) {if(a){cout << "YES" << ENT;}else{cout << "NO" << ENT;}}


vector<int> used;
vector<vector<int>> connect;
int n,m;


int dfs(int now, int depth) {
    if (used[now]) return 0;
    if (depth == n) return 1;

    used[now] = 1;
    int ret = 0;

    for (int i = 0; i < n; i++){
        if (connect[now][i]) ret += dfs(i, depth + 1);
    }
    used[now] = 0;

    return ret;
}


int atcoder() {
    cin >> n >> m;
    vector<int> a(m),b(m);
    REP(i,0,m){
        cin >> a[i] >> b[i];
        a[i]--; b[i]--;
    }
    int ans;
    
    used = vector<int>(n,0);
    connect = vector<vector<int>> (n,vector<int>(n,0));
    REP(i,0,m) connect[a[i]][b[i]] = connect[b[i]][a[i]] = 1;
    
    ans = dfs(0,1);
    cout << ans << ENT;
    
    return 0;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    atcoder();
    return 0;
}
