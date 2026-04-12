#include<bits/stdc++.h>

#define rep(i,N) for(int i=0;i<N;i++)
#define rep2(i,N) for(int i=1;i<=N;i++)
using namespace std;
long long  INF=1e18;
long long mod=1e9+7;
int n,m;
vector<vector<int>>edge(10);


bool connect(int now,int next){

    for(auto ne:edge[now]){
        if(next==ne)return true;
    }
    return false;


}


bool check(vector<int>v){
    bool ok=true;
    rep(i,n-2){
        ok&=connect(v[i],v[i+1]);
    }

    return ok;
}




int main(){

    
    cin>>n>>m;

    

    rep(i,m){
        int a,b;
        cin>>a>>b;
        a--,b--;
        edge[a].emplace_back(b);
        edge[b].emplace_back(a);
    }
    bool start[n]={};
    rep(i,edge[0].size()){
        start[edge[0][i]]=true;
    }
    vector<int>v(n-1);
    rep(i,n-1)v[i]=i+1;

    long long ans=0;
    do{
        if(!start[v[0]])continue;

        if(check(v))ans++;

    }while(next_permutation(v.begin(),v.end()));
    
    cout<<ans<<endl;


    return 0;

}
/*


*/
