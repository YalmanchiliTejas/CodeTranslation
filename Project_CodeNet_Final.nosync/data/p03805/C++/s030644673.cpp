#include <bits/stdc++.h>
#include <stdlib.h>
#include <cmath>
using namespace std;

bool data[8][8];

int main(){
    int N,M;
    cin>>N>>M;
    
    for(int i=0;i<M;i++){
        int u,v;
        cin>>u>>v;
        u--;v--;
        data[u][v]=true;
        data[v][u]=true;
    }

    vector<int> v;
    for(int i=1;i<N;i++) v.push_back(i);

    int ans=0;
    if(N==2) ans=M;
    else{
        do{
            bool okay=true;
            if(data[0][v.at(0)]==false) okay=false;
            else{
                for(int i=0;i<N-2;i++){
                    if(data[v.at(i)][v.at(i+1)]==false) okay=false;
                }
            }
            if (okay) ans++;
            //if (okay) {for(int i=0;i<v.size();i++) {cout<<v.at(i)+1<<' ';} cout<<endl;}
        } while(next_permutation(v.begin(),v.end()));
    }

    cout<<ans<<endl;

}