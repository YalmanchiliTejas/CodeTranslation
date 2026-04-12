#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <random>
#include <chrono>
#include <queue>
#include <ctime>
#include <cassert>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;
#define fs first
#define sc second
#define INF 1000000000
#define MOD 1000000007
#define EPS 0.00000001

int N, M;
vector<vector<int>> T;
int cnt = 0;
vector<bool> visited;

void dfs(int s){
    visited[s] = true;
    for(int i=0; i<(int)T[s].size(); i++){
        if(!visited[T[s][i]]) dfs(T[s][i]);
    }
    
    bool ok = true;
    for(int i=0; i<N; i++){
        if(!visited[i]) ok = false;
    }
    if(ok) cnt++;
    visited[s] = false;
    return;
}




int main() {
    cin >> N >> M;
    visited.resize(N);
    T.resize(N);
    for(int i=0; i<M; i++){
        int a, b; cin >> a >> b;
        a--; b--;
        T[a].push_back(b);
        T[b].push_back(a);
    }
    
    dfs(0);
    cout << cnt << endl;
    return 0;
}

