#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;


vector<ii> pointsX;
vector<ii> pointsY;

vector<pair<int, ii>> edges;
int parents[1000002];

int find(int x){
    if(parents[x] == x){
        return x;
    }
    parents[x] = find(parents[x]);
    return parents[x];
}

int main(){
//    freopen("A.inp", "r", stdin);

    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        parents[i] = i;
        int a, b;
        cin >> a >> b;
        pointsX.push_back(ii(a, i));
        pointsY.push_back(ii(b, i));
    }

    sort(pointsX.begin(), pointsX.end());
    sort(pointsY.begin(), pointsY.end());

    for(int i = 0; i < n - 1; i++){
        int w = abs(pointsX[i].first - pointsX[i + 1].first);
        ii e = ii(pointsX[i].second, pointsX[i + 1].second);
        edges.push_back(pair<int, ii>(w, e));
        w = abs(pointsY[i].first - pointsY[i + 1].first);
        e = ii(pointsY[i].second, pointsY[i + 1].second);
        edges.push_back(pair<int, ii>(w, e));
    }

    sort(edges.begin(), edges.end());
    int use = 0;
    int ans = 0;
    for(int i = 0; i < edges.size(); i++){
        int st = find(edges[i].second.first);
        int en = find(edges[i].second.second);

        if(st != en){
            ans += edges[i].first;
            parents[st] = en;
            use++;
        }
        if(use == n - 1){
            cout << ans;
            return 0;
        }

    }

    cout << ans;

    return 0;

}

