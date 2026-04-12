#include <bits/stdc++.h>
using namespace std;

const int MAX=10;
int N;
vector<int> S[MAX],state(MAX,0),point(MAX,0);
stack<int> T;

void DFS(){
    int cnt=0,c=9;
    T.push(0);
    state[0]=1;
    while(T.size()){
        int a=T.top();
        bool check=true;
        for(int i=point[a];i<S[a].size();i++){
            int b=S[a][i];
            if(state[b]==0){
                T.push(b);
                state[b]=1;
                point[a]=i+1;
                check=false;
                break;
            }
        }
        if(T.size()==N&&!check){
            cnt++;
        }
        point[c]=0;
        c=9;
        if(check){
            state[a]=0;
            c=a;
            T.pop();
        }
    }
    cout<<cnt<<endl;
}

int main(){
    
    int M;
    cin>>N>>M;
    for(int i=0;i<M;i++){
        int a,b;cin>>a>>b;
        a--;b--;
        S[a].push_back(b);
        S[b].push_back(a);
    }
    for(int i=0;i<N;i++){
        sort(S[i].begin(),S[i].end());
    }
    DFS();
}
