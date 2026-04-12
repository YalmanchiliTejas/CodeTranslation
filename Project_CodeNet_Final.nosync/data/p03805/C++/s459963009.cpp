#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <queue>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define REP(i, n) for(int i=0; i<n; i++)

int N,M;
vector<int> L[10];
bool isvisit[10];
ll ans;

void dfs(int v){
    isvisit[v] = true;
    bool update = false;
    for(int i = 0; i < L[v].size(); i++){
        int next = L[v][i];
        if(!isvisit[next]){
            dfs(next);
            update = true;
        }
    }

    if(!update){
        REP(i,N){
            if(!isvisit[i])
                goto fin;
        }
        ans++;
    }
fin:
    isvisit[v] = false;
}

int main(){
    cin >> N >> M;
    REP(i,M){
        int a, b;
        cin >> a >> b;
        a--, b--;
        L[a].push_back(b);
        L[b].push_back(a);
    }

    dfs(0);

    cout << ans << endl;
    return 0;
}
