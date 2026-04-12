#include <iostream>
#include <iomanip>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <tuple>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for(int i=0; i<n; i++)
#define rep2(i, s, e) for(int i=s; i<e; i++)
#define print(i) cout << i << endl;

int const NMAX = 8;
vector<int> v[NMAX];
int cnt = 0;
int n;
bool used[NMAX];

void dfs(int k, int done, int& cnt){

    // cout << " " << k+1 << " " << done <<  endl;

    done++;
    if(done == n){
        cnt++;
        return;
    }
    
    if(v[k].empty()){
        return;
    }
    else{
        for(auto x : v[k]){
            if(!used[x]){
                // cout << k << "->" << x << endl;
                used[x] = true;
                dfs(x, done, cnt);
                used[x] = false;
            }
        }
    }
}

int main(){

    int m; cin >> n >> m;

    rep(i, m){
        int a, b; cin >> a >> b;
        a--; b--;

        v[a].push_back(b);
        v[b].push_back(a);
    }

    fill(used, used+NMAX, false);
    used[0] = true;
    dfs(0, 0, cnt);

    cout << cnt;

    return 0;
}