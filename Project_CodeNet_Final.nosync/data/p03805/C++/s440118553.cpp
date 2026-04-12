#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <set>
#include <utility>
#include <cstdlib>
#include <queue>
#include <stack>
#include <iomanip>
#include <cstdio>
#include <map>

using namespace std;

#define rep(i,x) for(ll i = 0; i < (ll)(x); i++)
#define rrep(i,x) for(ll i = ((ll)(x) - 1); i >= 0; i--)
#define _upgrade ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(x) (x).begin(), (x).end()
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() );
#define pb push_back

typedef long long int ll;
typedef pair<int,int> P;

template<class T1, class T2> void chmin(T1 &a, T2 b){if(a>b)a=b;}
template<class T1, class T2> void chmax(T1 &a, T2 b){if(a<b)a=b;}

//ll gcd(ll a, ll b){return b?gcd(b,a%b):a;}
//ll lcm(ll x, ll y) {return x / gcd(x, y) * y;}

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
const ll LINF = 1001002003004005006ll;
const int INF = 1001001001;
const ll mod = 1e9 + 7;
const double PI = 3.14159265358979323846;


// ****************************************CODE***************************************//

const int nmax = 8;
bool graph[nmax][nmax];

int dfs(int v, int N, bool visited[nmax]){
        bool all_visited = true;

        for(int i = 0; i < N; i++){
                if(visited[i] == false) all_visited=false;
        }
        
        if(all_visited){
                return 1;
        }

        int ret = 0;
        
        for(int i = 0; i < N; i++){
                if(graph[v][i]==false) continue;
                if(visited[i]) continue;

                visited[i]=true;
                ret += dfs(i,N,visited);
                visited[i]=false;
        }

        return ret;
}

int main(void){
        int n,m;
        cin >> n >> m;

        for(int i = 0; i < m; i++){
                int a,b;
                cin >> a >> b;
                graph[a-1][b-1] = graph[b-1][a-1] = true;
        }

        bool visited[nmax];
        for(int i = 0; i < n; i++){
                visited[i] = false;
        }

        visited[0] = true;
        cout << dfs(0,n,visited) << endl;
        return 0;
}








