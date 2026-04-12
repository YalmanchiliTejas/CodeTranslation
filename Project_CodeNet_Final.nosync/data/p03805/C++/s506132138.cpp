#include<bits/stdc++.h>
using namespace std;
using Graph=vector<set<int>>;
#define rep(i,n) for(int i=0;i<(int)(n);i++)

int M;
int N;

void dfs(Graph G,vector<int> &A,const vector<int> B,int &cnt){
    if(A.size()==N-1){
        bool flag=true;
        vector<int>C=A;
        sort(C.begin(),C.end());
        if(C!=B){
            flag=false;
        }
        if(G[0].count(A[0])){
        }
        else{
            flag=false;
        }
        if(N>2&&flag){
            rep(i,N-2){
                if(G[A[i]].count(A[i+1])){
                }
                else{
                    flag=false;
                    break;
                }
            }
        }
        if(flag){
            cnt++;
        }
        return;
    }//数列のサイズがNになったら終わる
    for(int v=1;v<=N-1;v++){
        A.push_back(v);
        dfs(G,A,B,cnt);
        A.pop_back();
    }//0からMまで入れていく
}//M^N通りの数列を作ることができる

int main(){
    //頂点と辺の数を受け取る
    cin>>N>>M;
    //グラフのデータを受け取る
    Graph G(N);
    rep(i,M){
        int a,b;
        cin>>a>>b;
        a--;b--;
        G[a].insert(b);
        G[b].insert(a);
    }
    int cnt=0;
    vector<int>A;
    vector<int>B;
    rep(i,N-1){
        B.push_back(i+1);
    }
    dfs(G,A,B,cnt);
    cout<<cnt<<endl;
}
