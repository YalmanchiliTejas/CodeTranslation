#include <iostream>
#include <map>
#include <queue>
using namespace std;
typedef pair<int,int> P;
int N,M,K;
int D[110];
int ok[110] = {};
int V[110][110];
int dist[1<<16] = {};


int bfs(map<int,int> &m){
    dist[(1<<M)-1] = 0;
    queue<int> Q;
    Q.push((1<<M)-1);
    while(!Q.empty()){
        int S = Q.front(); Q.pop();
        for(int i=0;i<K;i++){
            int T = 0;
            for(int j=0;j<M;j++){
                if(!(S&(1<<j))) continue;
                int ne = V[D[j]][i];
                if(m.count(ne)) T |= (1<<m[ne]);
            }
            if(dist[T]==-1){
                dist[T] = dist[S]+1;
                Q.push(T);
            }
        }
    }
    return dist[0];
}

int main(){
    cin >> N >> M >> K;
    map<int,int> m;
    for(int i=0;i<M;i++){
        cin >> D[i];
        D[i]--;
        m[D[i]] = i;
    }
    for(int i=0;i<N;i++) for(int j=0;j<K;j++){cin >> V[i][j]; V[i][j]--;}
    for(int S=0;S<(1<<M);S++) dist[S] = -1;
    cout << bfs(m) << endl;
}
