#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep2(i,n) for(int i=1;i<(n);i++)
typedef long long ll;



int main(){
    int n; cin >> n;
    vector<string> s(n);
    rep(i,n) cin >> s[i];
    map<char,int> m,now;

    for(char x : s[0]){
        m[x]++;
    }

    rep2(i,n){
        for(char x: s[i]){
            now[x]++;
        }
        for(char c='a';c<='z';c++){
            m[c]=min(m[c],now[c]);
        }
        for(char c='a';c<='z';c++){
            now[c]=0;
        }
        
    }
    for(auto p: m){
        auto key = p.first;
        auto value = p.second;
        rep(i,value){
            cout << key;
        }
    }
    cout << endl;
}