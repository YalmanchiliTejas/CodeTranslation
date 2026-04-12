#include<bits/stdc++.h>
using namespace std;
#define arep(i,x,n) for(int i=int(x);i<(int)(n);i++)
#define rep(i,n) for(long long i = 0;i < n;++i)
#define pi 3.141592653589793
#define eps 0.00000001
#define INF 1e9+7  
using ll = long long; 
using P=pair<int,int>;
using lP=pair<ll,ll>;
using fP=pair<double,double>;

char a[105][105];
int main(){
    int h,w;
    cin>>h>>w;
    rep(i,h){
        rep(j,w){
            cin>>a[i][j];
        }
    }
    vector<int>row;
    rep(i,h){
        bool ok=true;
        rep(j,w){
            if(a[i][j]=='#'){
                ok=false;
                break;
            }
        }
        if(!ok)row.push_back(i);
    }
    vector<int>line;
    rep(i,w){
        bool ok=true;
        rep(j,h){
            if(a[j][i]=='#'){
                ok=false;
                break;
            }
        }
        if(!ok)line.push_back(i);
    }
    for(int x:row){
        for(int y:line){
        cout<<a[x][y];
    }
        cout<<endl;
    }
    return 0;
}