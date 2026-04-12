#include<bits/stdc++.h>
using namespace std;

void dfs(bool& end, int a, int b, vector<vector<int> >& adjlist, vector<int>& temp_node, vector<bool>& used){

    //cout << a << " ";
    if(a == b){
        end = true;
        return;
    }

    for(int i = 0; i < adjlist[a].size(); i++){
        
        if(used[adjlist[a][i]] == false){
            used[adjlist[a][i]] = true;
            temp_node.push_back(adjlist[a][i]);
            dfs(end, adjlist[a][i], b, adjlist, temp_node, used);
            if(end) return;
            temp_node.pop_back();
        }
    }
}

int main(){

    int r, c, m; cin >> r >> c >> m;
    vector<vector<bool> > room(r, vector<bool> (c, true));
    vector<vector<int> > on(r, vector<int> (c, 0));
    vector<vector<int> > off(r, vector<int> (c, 0));
    vector<vector<int> > per_time(r, vector<int> (c, 0));
    vector<int> x(m);
    vector<int> y(m);

    //入力
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            char input; cin >> input;
            if(input == '#') room[i][j] = false;
        }
    }

    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cin >> per_time[i][j];
        }
    }

    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cin >> on[i][j];
        }
    }

    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cin >> off[i][j];
        }
    }
    
    for(int i = 0; i < m; i++){
        cin >> x[i] >> y[i];
    }


    //mapの作成
    map<pair<int, int>, int> M;
    map<int, pair<int, int> > _M;
    int num = 0;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if(room[i][j] == true){
                M[make_pair(i, j)] = num;
                _M[num] = make_pair(i, j);
                num++;
            }
        }
    }

    //隣接リスト
    vector<vector<int> > adjlist(num);

    int di[4] = {0, 1, 0, -1};
    int dj[4] = {1, 0, -1, 0};
    //グラフを作成
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if(room[i][j] == true){
                for(int h = 0; h < 4; h++){
                    int ni = i + di[h];
                    int nj = j + dj[h];
                    if(0 <= ni && ni < r && 0 <= nj && nj < c){
                        if(room[ni][nj] == true){
                            int a = M[make_pair(i, j)];
                            int b = M[make_pair(ni, nj)];
                            adjlist[a].push_back(b);
                            //adjlist[b].push_back(a);                            
                        }
                    }
                }
            }
        }
    }
    
    //o

    vector<vector<int> > node(m);         //訪れる頂点の順番の配列
    node[0].push_back(M[make_pair(x[0],y[0])]);
    for(int i = 1; i < m; i++){
        int a = M[make_pair(x[i - 1], y[i - 1])];
        int b = M[make_pair(x[i], y[i])];
        vector<bool> used(num, false);
        bool end = false;
        used[a] = true;
        dfs(end, a, b, adjlist, node[i], used);
    }


    //x


    //訪れる時刻
    int nt = 0;
    vector<vector<int> > t(num, vector<int> (0));
    for(int i = 0; i < node.size(); i++){
        for(int j = 0; j < node[i].size(); j++){
            t[node[i][j]].push_back(nt);
            nt++;
        }
    }

    int ans = 0;
    for(int i = 0; i < num; i++){
        int ni = _M[i].first;
        int nj = _M[i].second;
        
        if(t[i].size() == 0) continue;
        else{
            ans += on[ni][nj] + off[ni][nj];
            for(int j = 1; j < t[i].size(); j++){
                ans += min(on[ni][nj] + off[ni][nj], (t[i][j] - t[i][j - 1])*per_time[ni][nj]);
            }
        }
    }

    cout << ans << endl;

    return 0;    
}
