#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
using namespace std;

#define ll long long
#define nmax 8

bool graph[nmax][nmax];

int dfs(int v, int N, bool visited[nmax]){
    bool all_visited = true;

    for(int i=0;i<N;i++){
        if(visited[i]==false)all_visited = false;
    }

    if(all_visited)return 1;    /*全訪問で+1*/

    int ret=0;

    for(int i=0;i<N;i++){
        if(graph[v][i]==false)continue;
        if(visited[i])continue; /*探索済みならばcontinue*/

        visited[i] = true;  /*未探索ならばvisited(true)へ変更*/
        ret += dfs(i,N,visited);
        visited[i]=false;
    }

    return ret;
}

int main(){

    int i,j,k;
    int N,M;
    cin >> N >> M;

    for(i=0;i<M;i++){
        int A,B;
        cin >> A >> B;
        graph[A-1][B-1] = graph[B-1][A-1] = true;
    }

    bool visited[nmax];

    for(i=0;i<N;i++){
        visited[i] = false;
    }
    
    visited[0] = true;

    cout << dfs(0,N,visited) << endl;

    return 0;

}
