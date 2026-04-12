#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> G[100000];
bool used[100000];
bool second = true;

int dfs(int v){
    int ret = 0;
    int cnt = 0;
    used[v] = true;
    for(int i = 0; i < G[v].size(); i++){
        if(!used[G[v][i]]){
            cnt++;
            ret += dfs(G[v][i]);
        }
    }
    //cout << v << ' ' << cnt << endl;
    if(ret == 0) return 1;
    if(ret >= 2) {
        //cout << v << endl;
        second = false;
        return 0;
    }
    return 0;
}

int main(){
    cin >> N;
    for(int i = 0; i < N-1; i++){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    if(N%2 == 1){
        cout << "First" << endl;
        return 0;
    }
    dfs(0);
    if(second){
        cout << "Second" << endl;
    }else{
        cout << "First" << endl;
    }
}