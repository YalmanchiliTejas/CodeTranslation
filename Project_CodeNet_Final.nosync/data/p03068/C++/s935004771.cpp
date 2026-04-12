#include <bits/stdc++.h>
using namespace std;

int main(void){
    int N,K;
    string S;
    char key;
    cin>>N>>S>>K;
    key = S[K-1];
    for(int i = 0; i<N; i++){
        if(S[i] != key){
            S[i] = '*';
        }
    }
    cout<<S<<endl;
    return 0;
}