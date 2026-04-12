#include<bits/stdc++.h>
#define REP(i,n) for(int i=0;i<n;i++)
using namespace std;
int main(){
    int N,K;
    string S;
    cin>>N>>S>>K;
    char b=S[K-1];
    REP(i,S.size()){
        if(S[i]!=b){
            printf("*");
        } else {
            printf("%c",S[i]);
        }
    }
    printf("\n");
}