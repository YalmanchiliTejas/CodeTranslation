//g++でビルド

#include "bits/stdc++.h"

using namespace std;

int n, m;
vector<int> fronts, backs;

int dfs(vector<bool> bools, int s){
    bools[s-1] = true;
    bool last = true;
    for(int i = 0; i < n; i++){
        last = last && bools[i];
    }
    if(last){
        return 1;
    }
    set<int> next;
    for(int i = 0; i < fronts.size(); i++){
        if(fronts[i] == s){
            int back = backs[i];
            if(!bools[back-1]){
                next.insert(back);
            }
        }
    }

    int sum = 0;
    for(int item : next){
        sum += dfs(bools, item);
    }

    return sum;

}

int main(){
    cin >> n >> m;
    for(int i = 0; i<m; i++){
        int a, b;
        cin >> a >> b;
        fronts.push_back(a);
        backs.push_back(b);
        fronts.push_back(b);
        backs.push_back(a);
    }
    vector<bool> bools(n, false);
    int result = dfs(bools, 1);
    

    cout << result << endl;
    return 0;
}