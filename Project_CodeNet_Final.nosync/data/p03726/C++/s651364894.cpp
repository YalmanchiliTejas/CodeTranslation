#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=100005,INF=1<<30;
vector<int> G[MAX],deg(MAX),used(MAX);
queue<int> Q;
int N;
bool ok=true;

void BFS(){
    while(!Q.empty()){
        int a=Q.front();Q.pop();
        if(used[a]) continue;
        used[a]=1;
        for(int i=0;i<G[a].size();i++){
            int b=G[a][i];
            if(!used[b]){
                used[b]=1;
                for(int j=0;j<G[b].size();j++){
                    int c=G[b][j];
                    if(!used[c]){
                        deg[c]--;
                        if(deg[c]==1) Q.push(c);
                        //break;
                    }
                }
                break;
            }
            if(i==G[a].size()-1) ok=false;
        }
    }
}

int main(){
    
    cin>>N;
    for(int i=0;i<N-1;i++){
        int a,b;cin>>a>>b;
        a--;b--;
        G[a].push_back(b);
        G[b].push_back(a);
        deg[a]++;
        deg[b]++;
    }
    
    for(int i=0;i<N;i++){
        if(deg[i]==1){
            Q.push(i);
            //used[i]=1;
        }
    }
    
    if(N%2==1){
        cout<<"First"<<endl;
        return 0;
    }
    
    BFS();
    
    if(!ok) cout<<"First"<<endl;
    
    else cout<<"Second"<<endl;
}




