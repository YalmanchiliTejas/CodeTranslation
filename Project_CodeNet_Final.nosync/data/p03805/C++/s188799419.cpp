#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

#define MP make_pair
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define VI vector<int>
#define PII pair<int, int>
#define FI first
#define SE second
#define ALL(x) (x).begin(), (x).end()
///////////////////

const int MX = 10;
int a[MX][MX];
bool visited[MX];

int dfs(int s, int n, bool* visited){
    bool av =  true;
    int ans = 0;
    for(int i=1;i<=n;i++){
        if(visited[i] == false){
            av = false;
            break;
        }
    }
    if(av){
        return 1;
    }

    for(int i=1;i<=n;i++){
        if(a[s][i] == 1 && visited[i] == false){
            visited[i] = true;
            ans += dfs(i,n,visited);
            visited[i] = false;
        }
    }
    return ans;
}

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);

    int n,m; scanf("%d %d", &n, &m);
    for(int i=0;i<m;i++){
        int f,t; scanf("%d %d", &f, &t);
        a[f][t] = 1;
        a[t][f] = 1;
    }

    visited[1] = true;
    cout << dfs(1, n, visited);
    return 0;
}
