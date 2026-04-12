#include<bits/stdc++.h>

using namespace std;
using ll = long long;
const ll mod = 1000000007;

const vector<vector<int>> dir2 = {{0, 1}, {1, 0}};
const vector<vector<int>> dir8 = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}, {1, 1}, {-1, 1}, {1, -1}, {-1, -1}};

int main()
{
    int h, w;
    cin >> h >> w;
    vector<vector<bool>> mp(h + 2, vector<bool>(w + 2)), seen(h + 2, vector<bool>(w + 2));
    for(int i = 1; i <= h; i++){
        for(int j = 1; j <= w; j++){
            char t; cin >> t;
            mp[i][j] = (t == '#');
        }
    }

    queue<pair<int,int>> que;
    que.push({1,1});

    while(que.size()) {
        auto cur = que.front();
        que.pop();
        int cnt = 0;
        mp[cur.first][cur.second] = 0;
        seen[cur.first][cur.second] = 1;
        for(auto i : dir2) {
            if(mp[i[0] + cur.first][i[1] + cur.second]){
                cnt++;
                que.push({i[0] + cur.first, i[1] + cur.second});
            }
            if(cnt == 2) {
                cout << "Impossible" << endl;
                return 0;
            }
        }
    }
    for(int i = 0; i <= h + 1; i++){
        for(int j = 0; j <= w + 1; j++){
            if(mp[i][j]){cout << "Impossible" << endl;
            return 0;}
        }
    }

    if(seen[h][w])
    cout << "Possible" << endl;
    else
    assert(0);
}