#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

int main(void){
    int N,K;
    string S;
    cin>>N>>S>>K;
    for(int i=0;i<N;i++){
        if(S.at(i)==S.at(K-1)) cout<<S.at(i);
        else cout<<"*";
        if(i==N-1) cout<<endl;
    }
    return 0;
}