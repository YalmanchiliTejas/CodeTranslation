#include<bits/stdc++.h>

using namespace std;

int N,M;
vector<vector<int>> neighbor;
int res = 0;

void dfs(int now, int reached){
    if(reached == (1<<N)-1)res++;
    else{
        for(int neigh : neighbor.at(now)){
            if((1<<(neigh-1)) & reached)continue;
            else dfs(neigh, reached + (1<<(neigh-1)));
        }
    }
}

int main(){
    cin >> N >> M;

    neighbor = vector<vector<int>>(N+1, vector<int>(0));
    for(int i=0; i<M; i++){
        int a,b;
        cin >> a >> b;
        neighbor.at(a).push_back(b);
        neighbor.at(b).push_back(a);
    }

    dfs(1, 1);

    cout << res << endl;
}