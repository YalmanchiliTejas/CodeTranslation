#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int mn[26],c[60][26];

int main(){
    int n;
    cin>>n;
    rep(i,n){
        string s;
        cin>>s;
        rep(j,s.size()){
            c[i][s[j]-'a']++;
        }
    }
    string ans="";
    rep(i,26)mn[i]=1e9;
    rep(i,n){
        rep(j,26){
            mn[j]=min(mn[j],c[i][j]);
        }
    }
    rep(i,26)if(mn[i]!=1e9)cout<<string(mn[i],char('a'+i));
    cout<<endl;
}