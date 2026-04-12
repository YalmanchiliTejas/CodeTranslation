#include<bits/stdc++.h>
using namespace std;

struct Node{
    int num,flag;
};

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    vector<int> graph[9];
    for(int i=0;i<m;++i){
        int a,b;
        scanf("%d %d",&a,&b);
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int cnt = 0;
    for(int i=0;i<graph[1].size();++i){
        queue<Node> que;
        que.push((Node){graph[1][i],1});
        while(!que.empty()){
            Node now = que.front();que.pop();
            if(now.flag & (1<<(now.num-1)))continue;
            if((now.flag | (1<<(now.num-1))) == ((1<<n)-1)){
                ++cnt;
                continue;
            }
            for(int j=0;j<graph[now.num].size();++j){
                que.push((Node){graph[now.num][j],now.flag|(1<<(now.num-1))});
            }
        }
    }
    printf("%d\n",cnt);

    return 0;
}
