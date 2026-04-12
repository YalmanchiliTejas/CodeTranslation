#include <bits/stdc++.h>
using namespace std;

vector<int> e[100];
int n,m;

int main() {

    cin >> n >> m;

    for(int i=0; i<m; i++){
        int a,b;
        cin >> a >> b;
        e[a].push_back(b);
        e[b].push_back(a);
    }

    vector<int> start;
    start.push_back(1);

    pair<vector<int>,int> now = make_pair(start,1);

    queue<pair<vector<int>,int>> q;

    q.push(now);

    int ans = 0;

    while(!q.empty()){

        now = q.front();
        q.pop();

        if(now.first.size() == n){
            ans++;
            continue;
        }

        for(int i=0; i<e[now.second].size(); i++){
            pair<vector<int>,int> tmp = now;
            bool flag = true;
            for(int j=0; j<tmp.first.size(); j++){
                if(e[now.second][i] == tmp.first[j]){
                    flag = false;
                    break;
                }
            }

            if(flag){
                tmp.first.push_back(e[now.second][i]);
                tmp.second = e[now.second][i];
                q.push(tmp);
            }

        }

    }

    cout << ans << endl;

    return 0;
}