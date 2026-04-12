#include <bits/stdc++.h>
using namespace std;

//関数


int main() {
    
    
    //入力
    long N,M;
    cin>>N>>M;
    vector<vector<bool>> edge(N,vector<bool>(N,false));
    for(int i=0;i<M;i++){
        long a,b;
        cin>>a>>b;
        edge.at(a-1).at(b-1)=true;
        edge.at(b-1).at(a-1)=true;
    }
    
    //計算
    vector<long> path(N-1);
    for(int i=0;i<N-1;i++){
        path.at(i)=i+1;
    }
    
    long ans=0;
    do{
        bool possible=edge.at(0).at(path.at(0));
        for(int i=1;i<N-1;i++){
            possible&=edge.at(path.at(i-1)).at(path.at(i)) ;
        }
        if(possible) ans++;
    }while(next_permutation(path.begin(),path.end()));
    
    //出力
    cout<<ans<<endl;
}