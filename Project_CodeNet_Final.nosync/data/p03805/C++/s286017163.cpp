#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

long long MOD = 1000000007;

vector<vector<int> > path_list(8,vector<int>(0));
int ans=0;
int N,M;
int dfs(vector<int> passed, int cnt, int node){
    if(passed[node]==1)return 0;
    else{
        cnt++;
        passed[node]=1;
    }

    if(cnt==N){
        ans++;
        return 0;
    }

    for(int i=0; i<(int)path_list[node].size(); i++){
        dfs(passed, cnt, path_list[node][i]);
    }
}

int main(){
    cin >> N >> M;
    
    for(int i=0; i<M; i++){
        int a,b;
        cin >> a >> b;
        a--;b--;
        path_list[a].push_back(b);
        path_list[b].push_back(a);
    }
    vector<int> passed(8,0);
    dfs(passed, 0, 0);

    cout << ans << endl;
}