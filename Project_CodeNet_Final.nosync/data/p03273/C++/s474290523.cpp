#include<bits/stdc++.h>
#define rep(i,a) for(int i=0;i<a;i++)
using namespace std;
int main(){
    int h,w;
    cin>>h>>w;
    string s[h];
    rep(i,h){
        cin>>s[i];
    }
    bool ok=true;
    rep(i,h){
        rep(j,w){
            if(s[i][j]=='#'){
                ok=false;
                break;
            }
        }
        if(ok){
            rep(k,w){
                s[i][k]='a';
            }
        }
        ok=true;
    }
    rep(i,w){
        rep(j,h){
            if(s[j][i]=='#'){
                ok=false;
                break;
            }
        }
        if(ok){
            rep(k,h){
                s[k][i]='a';
            }
        }
        ok=true;
    }
    bool ent=false;
    rep(i,h){
        rep(j,w){
            if(s[i][j]=='a') continue;
            cout<<s[i][j];
            if(s[i][j]=='#') ent=true;
        }
        if(ent) cout<<endl;
        ent=false;
    }
}