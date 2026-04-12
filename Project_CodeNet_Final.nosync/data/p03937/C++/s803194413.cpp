#include <bits/stdc++.h>
typedef long long int ll;
typedef long double ld;
using namespace std;

ll h,w;
char a[100][100];

void search(ll x,ll y){

    a[x][y]='.';
    if(a[x+1][y]=='#'){
        search(x+1,y);
    }else if(a[x][y+1]=='#'){
        search(x,y+1);
    }
    return;
}

void solve(){
    bool flag=true;
    string ans="Possible";

    cin>>h>>w;
    for(ll i=0;i<h;++i){
        for(ll j=0;j<w;++j){
            cin>>a[i][j];
        }
    }

    if(a[0][0]=='#'){
        search(0,0);
    }else{
        cout<<ans<<endl;
    }

    for(ll i=0;i<h;++i){
        for(ll j=0;j<w;++j){
            if(a[i][j]=='.'){
                continue;
            }else{
                flag=false;
                break;
            }
        }
    }
    if(flag){
        cout<<"Possible"<<endl;
        return;
    }else{
        cout<<"Impossible"<<endl;
        return;
    }
}

int main(){
    solve();
}
