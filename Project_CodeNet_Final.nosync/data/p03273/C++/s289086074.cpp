#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
ll n,m;
char s[105][105];
bool S[105][105];
int main(void){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>s[i][j];
            S[i][j]=true;
        }
    }
    bool t;
    for(int i=0;i<n;i++){
        t=true;
        for(int j=0;j<m;j++){
            if(s[i][j]=='#'){
                t=false;
            }
        }
        if(t==true){
            for(int j=0;j<m;j++){
                S[i][j]=false;
            }
        }
    }
    for(int i=0;i<m;i++){
        t=true;
        for(int j=0;j<n;j++){
            if(s[j][i]=='#'){
                t=false;
            }
        }
        if(t==true){
            for(int j=0;j<n;j++){
                S[j][i]=false;
            }
        }
    }
    for(int i=0;i<n;i++){
        t=false;
        for(int j=0;j<m;j++){
            if(S[i][j]){
                cout<<s[i][j];
                t=true;
            }
        }
        if(t) cout<<endl;
    }
    
}
