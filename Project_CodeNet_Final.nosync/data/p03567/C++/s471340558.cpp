#include<bits/stdc++.h>
using namespace std;
#define FOR(i,l,r) for(long long i=(l);i<(r);++i)
#define REP(i,n) FOR(i,0,n)
#define int long long
 
signed main(){
    string S;
    cin>>S;
    bool ok=false;
    REP(i,S.size()-1){
        if(S[i]=='A'&&S[i+1]=='C')ok=true;
    }
    if(ok)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}