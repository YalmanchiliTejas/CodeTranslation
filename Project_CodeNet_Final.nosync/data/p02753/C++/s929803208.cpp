#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0;i<n;i++)
#include <bits/stdc++.h>
#include <numeric>
using namespace std;
typedef long long ll;


int main() {
    string S;
    cin>>S;
    int countB=0;
    int countA=0;
    rep(i,3){
        if(S[i]=='B')countB++;
    }
     rep(i,3){
        if(S[i]=='A')countA++;
    }
    if(countB==3||countA==3)cout<<"No"<<endl;
    else cout<<"Yes"<<endl;
}