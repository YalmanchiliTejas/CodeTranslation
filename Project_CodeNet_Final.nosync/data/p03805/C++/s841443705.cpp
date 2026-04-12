#include <bits/stdc++.h>
using namespace std;

map<int,vector<int>> P;
set<string> RT;
vector<bool> ans;
int count1=0;
void prog(int a,vector<bool>T){
    T.at(a-1)=true;
    if(T==ans){
        count1++;
        return;
    }
    for(int i:P.at(a)){
        if(T.at(i-1))continue;
      prog(i,T);
    }
}

int main (){
    int N,M;
    cin >> N >> M;
    for(int i=0;i<M;i++){
        int j,k;
        cin >> j >> k;
        P[j].push_back(k);
        P[k].push_back(j);
    }
    
    
    ans=vector<bool>(N,true);
    
    prog(1,vector<bool>(N,false));
    
    
    cout << count1 << endl;
    
}
