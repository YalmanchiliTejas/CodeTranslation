#define _GLIBCXX_DEBUG//TLEの原因になるので注意！！！！！！！！！！！
#include<cmath>
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
vector<int> arr;
stack<int> st;
queue<int> qu;
queue<pair<int,int> > qu2;
priority_queue<int> pq;
#define rep(i,n) for(int i=0; i<(int)(n); i++)
#define rep2(i,n) for(int i=1; i<=(int)(n); i++)
#define mins(x,y) x=min(x,y)
#define maxs(x,y) x=max(x,y)
typedef set<int> set_t;
typedef set<string> set_g;
typedef complex<double> xy_t;
static const int NIL = -1;
static const int INF = 1000000007;
#define mp make_pair
#define sz(x) int(x.xise())
#define mod 1000000007
#define reps(i,s,n) for(int i = s; i < n; i++)
//#define int long long

//cerrはコメントアウトしなくても通る//ただしTLEを引き起こすことがある

vector<int> to(8);
int visited[8];
int e[10][10];
int ans=0;
int n;

void dfs(int v){
    int all=1;
    rep(i,n){
        if(visited[i]==0){
            all=0;
        }
    }
    if(all){
        ans++;
        return;
    }
    rep(u,n){
        if(e[v][u]==1&&visited[u]==0){
            visited[u]++;
            dfs(u);
            visited[u]=0;
        }
    }
    return;
}

int main(){
    int m;
    cin >> n>> m;
    rep(i,m){
        int a,b;
        cin >> a>> b;
        a--;b--;
        e[a][b]=1;
        e[b][a]=1;
        //to[a].push_back(b);
        //to[b].push_back(a);
    }
    visited[0]=1;
    dfs(0);
    cout<<ans<<endl;
    return 0;
}