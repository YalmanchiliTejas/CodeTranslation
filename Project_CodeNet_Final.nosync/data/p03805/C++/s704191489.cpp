#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <numeric>
#include <unordered_map>

using namespace std;

int sum = 0;
void dfs(const int& now, vector<int>& color, const vector<vector<int>>& adjlist);

int main(){
    int n,m;
    cin >> n >> m;

    vector<vector<int>> adjlist(n,vector<int>{});

    for(int i=0; i<m; i++){
        int tmp1,tmp2;
        cin >> tmp1 >> tmp2;
        tmp1--;
        tmp2--;
        adjlist[tmp1].push_back(tmp2);
        adjlist[tmp2].push_back(tmp1);
    }

    vector<int> color(n,0);

    dfs(0,color,adjlist);

    cout << sum << endl;

    return 0;
}

void dfs(const int& now, vector<int>& color, const vector<vector<int>>& adjlist){

    color[now] = 1;

    if(find(color.begin(),color.end(),0) == color.end()){
        sum++;
        color[now] = 0;
        return;
    }

    for(auto i:adjlist[now]){
        if(color[i]==0){
            dfs(i,color,adjlist);
        }
        
    }

    color[now] = 0;
}