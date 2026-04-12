#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    string S;
    int K;
    cin>>N>>S>>K;
    char c=S[K-1];
    for(int i=0;i<N;i++){
        if(S[i]==c){
            cout<<c;
        }
        else{cout<<"*";}
    }
    cout<<endl;
}