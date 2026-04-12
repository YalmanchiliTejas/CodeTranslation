#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <tuple>
using namespace std;
typedef pair<int,int> P;
int V[100][100];//[v][i] leads to
int isDark[100];//-1???????????????.0~M-1??§??????
const int INF = 100000;
int D[16];
int N,M,K;

int dist[1<<16];
int move_to[1<<16][100];
bool isvisit[1<<16];

int main(){
    cin>>N>>M>>K;
    fill(isDark,isDark+100,-1);
    fill(dist,dist+(1<<16),INF);
    fill(isvisit,isvisit+(1<<16),false);
    for(int i=0;i<M;i++){
        cin>>D[i];
        D[i]--;
        isDark[D[i]]=i;
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<K;j++){
            cin>>V[i][j];
            V[i][j]--;
        }
    }
    for(int b=0;b<(1<<M);b++){
        for(int k=0;k<K;k++){
            move_to[b][k]=0;
            for(int m=0;m<M;m++){
                if(b&(1<<m)){
                    int to = V[D[m]][k];
                    if(isDark[to]!=-1){
                        move_to[b][k]|=1<<isDark[to];
                    }
                }
            }
        }
    }
    deque<P> que;
    dist[(1<<M)-1]=0;
    que.emplace_back(0,(1<<M)-1);
    while(!que.empty()){
        int d,v;
        tie(d,v)= que.front(); que.pop_front();
        if(!v){
            cout<<d<<endl;
            return 0;
        }
        if(isvisit[v]) continue;
        isvisit[v]=true;
        for(int k=0;k<K;k++){
            int to = move_to[v][k];
            if(dist[to]>d+1){
                que.emplace_back(d+1,to);
                dist[to]=d+1;
            }
        }
    }

    return 0;
}