#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;
using ll = long long ;
const int INF = 1001001001;


int main() {

    int x,y;
    cin >> x >> y ;
    string board[x];
    bool goodx[x],goody[y];
    for(int i=0;i<x;i++){
            cin >> board[i] ;
            goodx[i] = false ;
    } 

    for(int i=0;i<y;i++){
            goody[i] = false ;
    } 

    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            if(board[i][j]=='#'){
                goodx[i]=true;
                goody[j]=true;
            }
            }
    }

    for(int i=0;i<x;i++){
        if(goodx[i]){
        for(int j=0;j<y;j++){
            if(goody[j]){
                cout << board[i][j] ;
            }
        }
                cout << endl ;
        }
    }

    return 0 ;
}