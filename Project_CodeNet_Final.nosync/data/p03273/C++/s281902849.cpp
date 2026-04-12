#include <bits/stdc++.h>
typedef long long int ll;
typedef long double ld;
using namespace std;

ll h,w;
char a[101][101];

int search(ll x,ll y){
    ll flag=0;
    for(ll i=0;i<w;++i){
        if(a[x][i]=='#'){
            flag++;
        }
    }
    if(flag==0){
        return false;
    }
    flag=0;
    for(ll i=0;i<h;++i){
        if(a[i][y]=='#'){
            flag++;
        }
    }
    if(flag==0){
        return false;
    }
    return true;
}

int main(){
    cin>>h>>w;
    bool bol=false;
    for(ll i=0;i<h;++i){
        for(ll j=0;j<w;++j){
            cin>>a[i][j];
        }
    }

    for(ll i=0;i<h;++i){
        for(ll j=0;j<w;++j){
            if(a[i][j]=='#'){
                cout<<'#';
                bol = true;
            }else{
                if(search(i,j)){
                    cout<<'.';
                    bol = true;
                }
            }
        }
        if(bol){
            cout<<endl;
        }
        bol = false;
    }
    return 0;
}