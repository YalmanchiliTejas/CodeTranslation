//hinagata.cpp
//作成日
//更新日
//目的
//手段
/*includes*/
#include <bits/stdc++.h>
/*namespace*/
using namespace std;
using ll= long long;
/*define macro*/
#define REP(i,n) for(ll i=0;i<(n);i++)
#define REPi(i,a,b) for(ll i=(a);i<(b);i++)
#define REPRi(i,a,b) for(ll i=(a);i>(b);i--)
#define ALL(x) (x).begin(),(x).end()


int main(){
int N,M;
cin>>N>>M;
vector<vector<int>> E(N,vector<int>(N,0));
REP(i,M){
    int a,b;
    cin>>a>>b;
    E[a-1][b-1]=1;
    E[b-1][a-1]=1;
}
//input end
vector<int> P(N);
REP(i,N){
    P[i]=i+1;
}
int count=0;
do{
    int flag=0;
    REPi(i,1,N){
        if(E[P[i]-1][P[i-1]-1]==0){
            flag=1;
        }
    }
    if(flag==0){
        count+=1;
    }
}while(next_permutation(P.begin()+1,P.end()));
cout<<count<<endl;
}