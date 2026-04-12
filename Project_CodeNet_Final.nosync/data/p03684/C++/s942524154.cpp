#include<bits/stdc++.h>
using namespace std;
#define INF 10000000


int prim(int v, vector<vector<pair<int, int> > > adjlist){

    priority_queue<pair<int, int> >  wait;    // first := 候補辺のコスト   second　:= 行先ノード
    vector<int> result(v, INF);               // 頂点iと木の間の最小コスト
    int ans = 0, size = 0;                    // 木のコスト　頂点数

    //初期条件
    result[0] = 0;
    wait.push(make_pair(0, 0));

    while(!wait.empty() && size < v){

        //候補辺のうち最小のものを取り出す
        int newpoint = wait.top().second;
        int newcost = -wait.top().first;
        wait.pop();

        if(result[newpoint] < newcost) continue;

        //出てきた頂点を木に追加
        ans += newcost;
        result[newpoint] = -INF;
        size++;

        // 新しい点から出ている辺をすべてなめる
        for(int i = 0; i < adjlist[newpoint].size(); i++){
            int nextpoint = adjlist[newpoint][i].second;
            int nextcost = adjlist[newpoint][i].first;
            //より木に近くなった頂点があれば,　そこへの枝をqueueに追加
            if(result[nextpoint] > nextcost){
                result[nextpoint] = nextcost;
                wait.push(make_pair(-nextcost, nextpoint));
            }
        }
    }

    return ans;
}


struct point{
    int idx, x, y;
};

bool comp_x(point a, point b){
    return a.x < b.x;
}

bool comp_y(point a, point b){
    return a.y < b.y;
}


int main(){

    int n; cin >> n;
    vector<point> vec(n);
    for(int i = 0; i < n; i++){
        int x, y; cin >> x >> y;
        vec[i].idx = i;
        vec[i].x = x;
        vec[i].y = y;
    }

    vector<vector<pair<int, int> > > adj(n);
    
    //xを基準にsort
    sort(vec.begin(), vec.end(), comp_x);
    for(int i = 0; i < n - 1; i++){
        int u = vec[i].idx;
        int v = vec[i + 1].idx;
        int cost = min((int)abs(vec[i].x - vec[i + 1].x), (int)abs(vec[i].y - vec[i + 1].y));
        adj[u].push_back({cost, v});
        adj[v].push_back({cost, u});
    }

    //y,,
    sort(vec.begin(), vec.end(), comp_y);
    for(int i = 0; i < n - 1; i++){
        int u = vec[i].idx;
        int v = vec[i + 1].idx;
        int cost = min((int)abs(vec[i].x - vec[i + 1].x), (int)abs(vec[i].y - vec[i + 1].y));
        adj[u].push_back({cost, v});
        adj[v].push_back({cost, u});
    }

    int ans = prim(n, adj);

    cout << ans << endl;
    return 0;
}