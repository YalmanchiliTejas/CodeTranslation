#include <bits/stdc++.h>
using namespace std;
int main(void){
    int N;cin>>N;
    string S;cin>>S;int K;cin>>K;
    char c=S[K-1];
    for(int i=0;i<N;i++){
        if(S[i]==c)continue;
        else S[i]='*';
    }
    cout<<S<<endl;
}