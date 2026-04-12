#include <bits/stdc++.h>
using namespace std;

int n, m;
int ans = 0;
vector<vector<int>> path;
void move(vector<int> p){
    if(p.size() == n) {
        ans++;
        return;
    }

    for (auto i : path[p[p.size() - 1]]) {
        vector<int> tmp = p;
        bool flg = true;
        for (int j : tmp) {
            if(j == i) {
                flg = false;
                break;
            }
        }
        if(not flg) continue;
        tmp.push_back(i);
        move(tmp);
    }
}

int main(){
    cin >> n >> m;

    path.assign(n, vector<int>(0));
    for (auto i = 0; i < m; i++) {
        int start, end;
        cin >> start >> end;

        path[start - 1].push_back(end - 1);
        path[end - 1].push_back(start - 1);
    }

    vector<int> start(0);
    start.push_back(0);
    move(start);

    cout << ans << endl;
    return 0;
}