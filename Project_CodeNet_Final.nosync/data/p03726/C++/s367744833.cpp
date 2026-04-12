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
#include <deque>
#include <algorithm>
using namespace std;

#define REP(i,n) for(int i=0; i<n; ++i)
#define FOR(i,a,b) for(int i=a; i<=b; ++i)
#define FORR(i,a,b) for (int i=a; i>=b; --i)
#define ALL(c) (c).begin(), (c).end()

typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<VI> VVI;
typedef vector<VL> VVL;
typedef pair<int,int> P;
typedef pair<ll,ll> PL;

const int N = 1e5;
set<int> e[N];

int main(){
    int n;
    cin >> n;
    REP(i,n-1){
        int u, v;
        scanf("%d %d", &u, &v);
        u--;
        v--;
        e[u].insert(v);
        e[v].insert(u);
    }

    VI visit(n);
    queue<int> que;
    REP(i,n){
        if (e[i].size() == 1){
            que.push(i);
        }
    }

    while (!que.empty()){
        int x = que.front();
        que.pop();
        if (visit[x]) continue;
        // cout << "now" << x << endl;
        // REP(i,n){
        //     cout << i << "  ";
        //     for (int p : e[i]) cout << p << " ";
        //     cout << endl;
        // }
        visit[x] = 1;
        if (e[x].size() == 0){
            cout << "First" << endl;
            return 0;
        }
        int y = *e[x].begin();
        e[x].erase(y);
        e[y].erase(x);
        visit[y] = 1;
        for (int z : e[y]){
            e[z].erase(y);
            if (e[z].size() == 0){
                cout << "First" << endl;
                return 0;
            }
            if (e[z].size() == 1 && !visit[z]){
                que.push(z);
            }
        }
        e[y].clear();
    }

    cout << "Second" << endl;

    return 0;
}




