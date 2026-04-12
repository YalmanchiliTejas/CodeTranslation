#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,l,n) for(int i=(l);i<(n);i++)
#define MAX 8
int N,M,MAX_N;
vector<vector<int>> edges(MAX,vector<int>(MAX,0));

int kai(int n){
    if(n==0) return 1;
    return 2*kai(n-1);
}

int dfs(int check,int parent){
    int sum=0;
    if(check==MAX_N) return 1;
    for(int child : edges[parent]){
        if((check & (1<<child))==0) sum+=dfs((check | (1<<child)),child); 
    }
    return sum;
}

int main(){
    cin >> N >> M;
    MAX_N = kai(N)-1;
    rep(i,M){
        int parent,child;
        cin >> parent;
        cin >> child;
        edges[parent-1].emplace_back(child-1);
        edges[child-1].emplace_back(parent-1);
    }
    cout << dfs(1,0) << endl; 
    return 0;
}