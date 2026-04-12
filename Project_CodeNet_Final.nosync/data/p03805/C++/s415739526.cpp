#include <iostream>
#include <vector>

using namespace std;

int count(vector<vector<int>>& vec, vector<bool> flag, int k){
    flag[k]=false;
    bool f=true;
    for(bool b : flag){
        if(b){
            f=false;
            break;
        }
    }
    if(f)
        return 1;
    int c=0;
    for(int v : vec[k]){
        if(flag[v]){
            c+=count(vec, flag, v);
        }
    }
    return c;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> vec(n);
    for(int i=0;i<n;++i){
        vec[i]=vector<int>(n-1);
    }
    int a, b;
    for(int i=0;i<m;++i){
        cin >> a >> b;
        --a; --b;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }
    //vector<bool> flag(n, true);
    cout << count(vec, vector<bool>(n, true), 0);
    return 0;
}