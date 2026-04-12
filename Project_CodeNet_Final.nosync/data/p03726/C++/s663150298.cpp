#include <bits/stdc++.h>

using namespace std;

const long long MOD=1e9+7;

bool hasMaxMatching(const vector<vector<int>>& tree){
    int n=tree.size();
    vector<bool> visited(n,false);
    vector<bool> matched(n,false);
    vector<int> preds(n,0);
    matched[0]=true;
    stack<int> si;
    si.push(1);
    visited[1]=true;
    while(!si.empty()){
        int cur=si.top();
        for(int i:tree[cur]){
            if(!visited[i]){
                si.push(i);
                preds[i]=cur;
                visited[i]=true;
            }
        }
        if(cur==si.top()){
            if(!matched[cur]&&!matched[preds[cur]]){
                matched[cur]=true;
                matched[preds[cur]]=true;
            }
            else if(!matched[cur] && matched[preds[cur]]){
                return false;
            }
            si.pop();
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin>>n;
    vector<vector<int>> tree(n+1);
    for(int i=1; i<n; i++){
        int x,y;
        cin>>x>>y;
        tree[x].push_back(y);
        tree[y].push_back(x);
    }
    bool b=hasMaxMatching(tree);
    cout<<(b?"Second":"First");
    
    
    return 0;
}
