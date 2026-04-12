#include<iostream>
#include<vector>

using namespace std;

bool graph[8][8]={};

int DFS (int v,int N,bool visited[8]/*訪れたノード*/){
    //最後かどうか確認する
    bool all_visited=true;
    for(int i=0;i<N;++i){
        if(visited[i]==false){
            all_visited=false;
        }
    }
    //最後だったら
    if(all_visited){
        return 1;
    }

    int ret=0;

    for(int i=0;i<N;++i){
        //道がなければ無視
        if(graph[v][i]==false)continue;
        //訪れたことがあればむし
        if(visited[i])continue;

        visited[i]=true;
        ret+=DFS(i,N,visited);
        visited[i]=false;
    }

    return ret;
}

int main(){
    int N,M;
    cin>>N>>M;

    for(int i=0;i<M;++i){
        int A,B;
        cin>>A>>B;
        graph[A-1][B-1]=graph[B-1][A-1]=true;
    }

    bool visited[8]={};

    visited[0]=true;
    cout<<DFS(0,N,visited)<<endl;
    return 0;


}