#include <bits/stdc++.h>
#include <string.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define FOR(i, m, n) for(int i = m; i < n; i++) 
#define mod 1000000007
typedef long long ll;
int main(){
    string S;
    cin>>S;
    int countA=0;
    int countB=0;
    rep(i,3){
        if(S[i]=='A'){
            countA++;
        }else{
            countB++;
        }
    }
    if(countA==3||countB==3){
        cout<<"No"<<endl;
    }else{
        cout<<"Yes"<<endl;
    }
    return 0;
}