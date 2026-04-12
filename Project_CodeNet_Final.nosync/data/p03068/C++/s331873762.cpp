#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define sz(x) int(x.size())
#define pb push_back
#define eb emplace_back
using ll=long long;
using P = pair<int,int>;
using LP=pair<ll,int>;
#define chmax(x,y) x = max(x,y)
#define chmin(x,y) x = min(x,y)
const ll MOD=1000000007,MOD2=998244353;



int main() {
    int N,K;
    string S;
    cin>>N>>S>>K;
    rep(i,N){
        if(S.at(K-1)==S.at(i)){
            cout<<S.at(i);
        }
        else{
            cout<<"*";
        }
    }
    cout<<endl;
}