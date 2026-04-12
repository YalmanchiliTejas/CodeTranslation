#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const int N = 1e4+50;
const ll oo = 1e18;
const ll mod = 1e9+7;


int main(){
    // 9opl.
    int n,m;
    cin>>n>>m;
    string x[n];
    for(int i=0;i<n;i++){
        cin>>x[i];
        bool ok=true;
        for(int j=0;j<m;j++)
            if(x[i][j]!='.'){
                ok=false;
                break;
            }
        if(ok){
            for(int j=0;j<m;j++){
                x[i][j]='@';
            }
        }
    }
    for(int i=0;i<m;i++){
        bool ok=true;
        for(int j=0;j<n;j++){
            if(x[j][i]=='@'||x[j][i]=='.')
                continue;
            ok=false;
            break;
        }
        if(ok){
            for(int j=0;j<n;j++){
                x[j][i]='@';
            }
        }
    }
    for(int i=0;i<n;i++){
        bool ok=true;
        for(int j=0;j<m;j++){
            if(x[i][j]=='@')
                continue;
            ok=false;
            cout<<x[i][j];
        }
        if(!ok)
            cout<<endl;
    }
    return 0;
}
