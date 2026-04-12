#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll r,c,k;
    cin>>r>>c;
    char grid[r][c],ans[r][c];
    for(ll i=0;i<r;i++){
        for(ll j=0;j<c;j++){
            cin>>grid[i][j];
            ans[i][j]=grid[i][j];
        }
    }
    for(ll i=0;i<r;i++){
        k=0;
        for(ll j=0;j<c;j++){
            if(grid[i][j]=='.')k++;
        }
        if(k==c){
            for(ll j=0;j<c;j++)ans[i][j]='o';
        }
    }
    for(ll i=0;i<c;i++){
        k=0;
        for(ll j=0;j<r;j++){
            if(grid[j][i]=='.')k++;
        }
        if(k==r){
            for(ll j=0;j<r;j++)ans[j][i]='o';
        }
    }
    for(ll i=0;i<r;i++){
        k=0;
        for(ll j=0;j<c;j++){
            if(ans[i][j]!='o')cout<<ans[i][j];
            else k++;
        }
        if(k!=c)cout<<'\n';
    }
    return 0;
}
