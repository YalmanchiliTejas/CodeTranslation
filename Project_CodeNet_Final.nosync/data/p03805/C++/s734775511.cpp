/*
 *
 * Author: r3gz3n
 * 
 * 3b 13 12 9 56 4e
 * 6 56 a a 5f f
 * 6 56 47 18 56 d
 * 13 46 14 1f 13 27
 * 52 52 a 5a 47 1
 * 1d 13 b 1b 49 17
 *
 */


#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;


#define pb push_back


#define rep(i, a, b, k) for(__typeof(a) i = a;i < b;i += k)

#define repeach(i, a) for(auto i: a)


#define endl '\n'


typedef vector<int> vii;


class Solution {
public:
    const int static MAX = 10;
    vii adj[MAX];
    int ans = 0, n;
    bool vis[MAX];

    void dfs(int from, int x) {
        vis[from] = true;
        x++;
        if (x == n) ans++;
        repeach(to, adj[from]) {
            if (vis[to] == false) {
                dfs(to, x);
            }
        }
        vis[from] = false;
    }

    void solve(std::istream& in, std::ostream& out) {
		int m, x, y;
        in >> n >> m;
        rep(i, 0, n+1, 1) vis[i] = false;
        rep(i, 0, m, 1) {
            in >> x >> y;
            adj[x].pb(y);
            adj[y].pb(x);
        }
        dfs(1, 0);
        out << ans << endl;
    }
};

void solve(std::istream& in, std::ostream& out)
{
    out << std::setprecision(12);
    Solution solution;
    solution.solve(in, out);
}


#include <fstream>
#include <iostream>


int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);


    istream& in = cin;


    ostream& out = cout;

    solve(in, out);
    return 0;
}


