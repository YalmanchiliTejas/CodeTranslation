#include <cstdio>
#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <cmath>
#include <functional>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#define rep(i,n) for (int i=0;i<n;i++)
using ll = long long;
using namespace std;

void solve(){

}
int main (){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int h,w;
    cin >> h >> w;
    vector<string> v(100);
    rep(i,h){
        cin >> v[i];
    }
    vector<bool> vertical(h,false);
    vector<bool> side(w,false);
    rep(i,h){
        rep(j,w){
            if(v[i][j]=='#'){
                vertical[i] = true;
                side[j] = true;
            }
        }
    }
    rep(i,h){
        if(vertical[i]){
            rep(j,w){
                if(side[j]){
                    cout << v[i][j];
                }
            }
            cout << endl;
        }
    }


    return 0;
}