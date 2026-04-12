#include<bits/stdc++.h>
using namespace std;
using Graph=vector<vector<int>>;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
typedef long long ll;
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

int main(){
    int N;cin>>N;
    vector<string>S(N);
    vector<vector<int>>ans(N,vector<int>(26,0));
    vector<int>A(26,50);
    rep(i,N){
        string T;
        cin>>T;
        sort(T.begin(),T.end());
        S[i]=T;
    }
    rep(i,N){
        rep(j,S[i].size()){
            ans[i][S[i][j]-'a']++;
        }
    }
    rep(i,26){
        rep(j,N){
            A[i]=min(A[i],ans[j][i]);
        }
    }
    rep(i,26){
        rep(j,A[i]){
            cout<<char('a'+i);
        }
    }
    cout<<""<<endl;
}