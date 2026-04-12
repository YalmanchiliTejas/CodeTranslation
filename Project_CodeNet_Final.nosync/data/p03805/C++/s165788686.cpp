#include <bits/stdc++.h>

using namespace std;



#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define euc_dis(x, y) sqrt(x*x + y*y)

#define pb push_back
#define mp make_pair
#define INF 999999999
#define sp ' '

int gcd(int a,int b){return b?gcd(b,a%b):a;}
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

typedef long long ll;
typedef pair<int, int> pint;
typedef vector<int> vint;
typedef vector<string> vstr;

vector<string> split(const string &str, char sep)
{
    vector<string> v;
    stringstream ss(str);
    string buffer;
    while( getline(ss, buffer, sep) ) {
        v.pb(buffer);
    }
    return v;
}

bool graph[8][8];
int dfs(int v, int n, bool visited[8]){
    bool all_visited = true;

    rep(i, n)
        if(!visited[i]) all_visited = false;
    if(all_visited) return 1;

    int ret = 0;
    rep(i, n){
        if(!graph[v][i]) continue;
        if(visited[i]) continue;

        visited[i] = true;
        ret += dfs(i, n, visited);
        visited[i] = false;
    }

    return ret;
}




int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    rep(i, m){
        int a,b;
        cin >> a >> b;
        graph[a-1][b-1]=graph[b-1][a-1]=true;
    }

    bool visited[8] = {false};
    visited[0] = true;
    cout << dfs(0, n, visited) << endl;

    return 0;
}
