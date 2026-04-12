#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

#define REP(i,n) for(int i=0; i<n; ++i)
#define FOR(i,a,b) for(int i=a; i<=b; ++i)
#define FORR(i,a,b) for (int i=a; i>=b; --i)
#define pi acos(-1.0)

typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<VI> VVI;
typedef pair<int,int> P;
typedef pair<ll,ll> PL;


int n, m;
vector<int> v[9];
bool searched[9] = {};
int ans = 0;

bool all_searched(){
    FOR(i, 1, n){
        if(!searched[i]) return false;
    }
    return true;
}


int dfs(int vertex){
    searched[vertex] = true;
    if(all_searched()){
        searched[vertex] = false;
        return 1;
    }
    int sum = 0;
    for(auto &adj : v[vertex]){
        if(searched[adj]) continue;
        sum += dfs(adj);
        searched[adj] = false;
    }
    return sum;
}


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    REP(i, m){
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    cout << dfs(1) << "\n";
    return 0;
}
