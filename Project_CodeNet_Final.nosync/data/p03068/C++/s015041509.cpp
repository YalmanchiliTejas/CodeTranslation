#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
using ll = long long;

int main(){
    // 制約見て！！！デカかったらlong longにすること！
    int N,K;
    string S;
    cin>>N>>S>>K;
    char c = S[K-1];
    rep(i,N){
        if(S[i]!=c){
            S[i] = '*';
        }
    }

    cout<<S<<endl;
}