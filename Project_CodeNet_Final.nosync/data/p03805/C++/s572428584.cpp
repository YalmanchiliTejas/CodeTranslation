#include <bits/stdc++.h>
using namespace std;
int N,M;
vector<vector<int>> relat(9,vector<int>(9,0));
vector<int> Flag(9,0);
int Count = 0;
bool all1(vector<int> flag){
    for(int i=1;i<=N;i++){
        if(flag[i] == 0) return false;
    }
    return true;
}

void dfs(int n,vector<int> flag){
    vector<int> vec = flag;
    vec[n] = 1;
    int check = 0;
    for(int i=1;i<=N;i++){
        if(relat[n][i]==1 && vec[i]!=1){
            dfs(i,vec);
            check = 1;
        }
    }
    if(check==0 && all1(vec)) Count++;
    return;
}

int main(){
    cin >> N >> M;
    for(int i=1;i<=M;i++){
        int a,b;
        cin >> a >> b;
        relat[a][b] = 1;
        relat[b][a] = 1;
    }
    dfs(1,Flag);
    cout << Count << endl;
    return 0;
}