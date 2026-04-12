#include <bits/stdc++.h>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <iostream>

#include <bitset>
#include <cassert>
#include <queue>
#include <random>
#include <stack>
#include <iomanip>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n;i++)
#define repf(i, a, b) for (int i = (int)a; i < (int)b;i++)
#define repv(x, arr) for (auto& x:arr)
#define all(v) (v).begin(), (v).end()
#define vec(name, num) vector<ll> name((num), 0);
#define mp(a,b) make_pair(a,b)
#define op(i) cout << (i) << endl;
#define F first
#define S second

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pdd;

const ll mod = 1e9 + 7;
ll ans = 0;

void go(vector<ll> visited,map<ll,set<ll>> &branch,ll N,ll &ans){
    /* for(auto x:visited){
        cout << x << " ";
    }
    cout << endl;*/
    if (visited.size() == N)
    {
        ans++;
        return;
    }
    for (auto x:branch[visited[visited.size()-1]]){
        bool flag = true;
        for (auto bef:visited){
            if (bef==x){
                flag = false;
            }
        }
        if(flag){
            vector<ll> visitedd = visited;
            visitedd.push_back(x);
            go(visitedd, branch, N,ans);
        }
    }
}

int main(){
    ll N, M;
    cin >> N >> M;
    map<ll, set<ll>> branch;
    ll a, b;
    rep(i,M){
        cin >> a >> b;
        a--;
        b--;
        branch[a].insert(b);
        branch[b].insert(a);
    }
    ll ans = 0;
    vector<ll> visited = {0};
    go(visited, branch, N, ans);
    cout << ans << endl;
}