#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <deque>
#include <iterator>
#include <iomanip>
#include <climits>
using namespace std;

vector<vector<long long> > g;
vector<bool> used;
vector<long long> a;
long long ans = 0, n;

void dfs(long long v){
    used[v] = true;
    for(int to: g[v]){
        if(!used[to]){
            a[to] = a[v] + 1;
            dfs(to);
        }
    }
    if(a[v] == n) ans++;
    used[v] = false;
}

int main(){
    long long m;
    cin >> n >> m;
    g.resize(n);
    used.assign(n, false);
    a.resize(n);
    long long fr, to;
    for(int i = 0; i < m; ++i){
        cin >> fr >> to;
        fr--, to--;
        g[fr].push_back(to);
        g[to].push_back(fr);
    }
    a[0] = 1;
    dfs(0);
    cout << ans;
}