#include <bits/stdc++.h>
#define range(i, a, n) for(int (i) = (a); (i) < (n); (i)++)
#define rep(i, n) for(int (i) = 0; (i) < (n); (i)++)
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;

using Cost = tuple<int, int, int>;

int h, w;
vector<string> field;
vector<vector<Cost>> cost;
vector<vvi> time_visited;
vector<pii> task;

vi dx = { 1, 0,-1, 0};
vi dy = { 0,-1, 0, 1};

bool dfs(pii pos, pii z, vector<pii> & route, vvi & used){
    if(used[pos.first][pos.second]) return false;
    used[pos.first][pos.second] = true;
    if(pos == z){
        route.push_back(pos);
        return true;
    }

    rep(i, 4){
        pii npos(pos.first + dy[i], pos.second + dx[i]);

        if(npos.first < 0 || h <= npos.first ||
           npos.second< 0 || w <= npos.second||
           field[npos.first][npos.second] == '#'){
            continue;
        }

        if(dfs(npos, z, route, used)){
            route.push_back(pos);
            return true;
        }
    }

    return false;
}

int main(void){
    int m; cin >> h >> w >> m;

    field = vector<string>(h);
    for(auto & e : field) cin >> e;

    cost = vector<vector<Cost>>(h, vector<Cost>(w));
    rep(y, h) rep(x, w) cin >> get<0>(cost[y][x]);
    rep(y, h) rep(x, w) cin >> get<1>(cost[y][x]);
    rep(y, h) rep(x, w) cin >> get<2>(cost[y][x]);

    task = vector<pii>(m);
    for(auto & e : task) cin >> e.first >> e.second;

    time_visited = vector<vvi>(h, vvi(w));
    pii pos = task[0];
    int t = 0;
    time_visited[pos.first][pos.second].push_back(t++);

    rep(i, m){
        vector<pii> route;
        vvi used(h, vi(w));

        dfs(pos, task[i], route, used);
        reverse(begin(route), end(route));

        for(auto & e : route){
            if(pos == e) continue;
            
            pos = e;
            time_visited[pos.first][pos.second].push_back(t++);
        }
    }

    int res = 0;
    rep(y, h){
        rep(x, w){
            int c_on, c_off, c_keep;
            tie(c_keep, c_on, c_off) = cost[y][x];

            if((int)time_visited[y][x].size() == 0) continue;

            res += c_on;
            rep(i, (int)time_visited[y][x].size() - 1){
                int diff = time_visited[y][x][i + 1] - time_visited[y][x][i];

                res += min(c_off + c_on, c_keep * diff);
            }
            res += c_off;
        }
    }

    cout << res << endl;

	return 0;
}