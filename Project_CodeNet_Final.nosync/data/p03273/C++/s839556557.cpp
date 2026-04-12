#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define rep(i,n) for(int i=0;i<n;i++)
int h,w;
char a[110][110];
bool x[110],y[110];
signed main(){
    cin>>h>>w;
    rep(i,h)x[i]=true;
    rep(i,w)y[i]=true;
    rep(i,h){
        rep(j,w){
            cin>>a[i][j];
            if(a[i][j]=='#'){
                x[i]=false;
                y[j]=false;
            }
        }
    }
    rep(i,h){
        rep(j,w){
            if(x[i]==true)continue;
            if(y[j]==true){
                if(j+1==w)cout<<endl;
                continue;
            }
            cout<<a[i][j];
            if(j+1==w)cout<<endl;
        }
    }
    return 0;
}