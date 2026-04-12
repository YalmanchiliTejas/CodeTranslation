#include <bits/stdc++.h>
using namespace std;
#define rep(i,ini,n) for(int i=ini;i<n;i++)
#define _rep(i,ini,n) for(int i=ini;i>=n;i--)
#define ToEnd(a) a.begin(),a.end()
uint64_t MOD=1000000007;

int64_t Dfs(int64_t level, int64_t k,vector<int64_t> A, vector<int64_t> P){
    if(level==0){
        if(k==0) return 0;
        else return 1;
    }

    if(k<2) return 0;
    else if(k<A.at(level-1)+2) return Dfs(level-1,k-1,A,P);
    else if(k<A.at(level-1)+3) return P.at(level-1)+1;
    else if(k<2*A.at(level-1)+3) return P.at(level-1)+1+Dfs(level-1,k-2-A.at(level-1),A,P);
    else return 2*P.at(level-1)+1;
}

int main(){
    int64_t N,X; cin>>N>>X;

    vector<int64_t> A(N+1,1),P(N+1,1);
    rep(n,0,N){
        A.at(n+1)=2*A.at(n)+3;
        P.at(n+1)=2*P.at(n)+1;
    }

    cout<<Dfs(N,X,A,P)<<endl;
}