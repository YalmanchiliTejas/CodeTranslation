#include <iostream>
#include <vector>
#include <cmath>
#include <set>
#include <algorithm>
#include <list>
#include <stdlib.h>
#include <stdio.h>
#include <queue>

using namespace std;
typedef long long ll;

static const int INF = (1<<21);
int d[100];

using Mat = vector<vector<int>>;
int N;

int dfs(int u,int N,Mat mat,bool visited[8]){
    
    bool all_visited = true;
    for(int i=0;i<N;i++){
        if(visited[i]==false){
            all_visited=false;
        }
    }
    if(all_visited){
        return 1;
    }
    int ret=0;
    visited[0]=true;
    for(int i=1;i<N;i++){
        if(mat[u][i]==0) continue;
        if(visited[i]) continue;

        visited[i]=true;
        ret+=dfs(i,N,mat,visited);
        visited[i]=false;
    }

    return ret;
}


int main() {
    int M;
    cin >> N >> M;
    Mat mat(N+10,vector<int>(N+10));
    vector<int> A(M+10),B(M+10);
    for(int i=0;i<M;i++){
        cin >> A[i] >> B[i];
        A[i]--,B[i]--;
        mat[A[i]][B[i]]=1;
        mat[B[i]][A[i]]=1;
    }
    bool visited[8];
    for(int i=0;i<N;i++){
        visited[i]=false;
    }
    int as = dfs(0,N,mat,visited);
    cout << as << endl;
}