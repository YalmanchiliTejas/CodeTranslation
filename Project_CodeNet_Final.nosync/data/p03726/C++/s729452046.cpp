#include <bits/stdc++.h>
using namespace std;

vector<int> edges[100000];

int dfs(int i, int par){
    int num = 0;
    for(int j : edges[i]){
        if(j != par) num += dfs(j, i);
    }
    if(num >= 2){
        cout << "First" << endl;
        exit(0);
    }else{
        return 1-num;
    }
}

int main(){
    int N;
    cin >> N;
    for(int i=0; i<N-1; i++){
        int a, b;
        cin >> a >> b;
        edges[a-1].push_back(b-1);
        edges[b-1].push_back(a-1);
    }

    int result = dfs(0, -1);
    cout << (result ? "First" : "Second") << endl;
    return 0;
}