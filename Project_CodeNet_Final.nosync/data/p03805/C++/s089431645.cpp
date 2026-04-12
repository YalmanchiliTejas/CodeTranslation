#include "bits/stdc++.h"
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size)
const long long mod = 1e9+7;
typedef priority_queue<int> PQ;
typedef vector<long long> Vl;
typedef vector<double> VI;  // VI a(n);
typedef vector<string> VS;  
typedef vector<VS> VSS;  
typedef vector<VI> VVI;   // VVI a(n,vector<int>(m)) n * m 
typedef vector<Vl> VVl;
typedef pair<int, int> PII;
typedef long long ll;  //ll とdoubleは違う
// cout << << endl;
// cin >> ;

const int nmax=8;
bool graph[nmax][nmax];

int dfs(int v, int N, bool visited[nmax]){
    bool all_visited=true;

    for(int i=0;i<N;i++){
        if(visited[i]==false)
            all_visited=false;
    }

    if (all_visited){
        return 1;
    }
    
    int ret=0;
    for(int i=0;i<N;++i){
        if(graph[v][i]==false) continue;
        if(visited[i]) continue;

        visited[i]=true;
        ret+=dfs(i,N,visited);
        visited[i]=false;
    }
    return ret;
}

int main(){
    ll c=0,d=0,k=0,n,m,h,w,p,q,ans=0;
    string s,s1,s2;
    cin >> n >> m;
    for(int i=0;i<m;++i){
        int A,B;
        cin >> A >> B;
        graph[A-1][B-1]=graph[B-1][A-1]=true;
    }

    bool visited[nmax];
    for(int i=0;i<n;++i){
        visited[i]=false;
    }

    visited[0]=true;
    cout << dfs(0,n,visited) << endl;
    return 0;
}