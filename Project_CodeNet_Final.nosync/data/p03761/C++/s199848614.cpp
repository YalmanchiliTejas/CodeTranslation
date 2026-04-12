#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(ll i=0;i<n;i++)
int main(void){
    int n;cin>>n;vector<string>v(n);rep(i,n)cin>>v.at(i);
    vector<vector<int>>A(26,(vector<int>(n,0)));
    rep(i,n){
        rep(j,v.at(i).size()){
            A.at(v.at(i).at(j)-97).at(i)++;
        }
    }
    int count=0;
    rep(i,26){
        rep(j,n){
            if(j==0)count=A.at(i).at(j);
            else count=min(count,A.at(i).at(j));
        }
        char x=i+97;
        rep(k,count)cout<<x;
    }
}