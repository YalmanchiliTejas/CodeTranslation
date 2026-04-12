#include <iostream>
#include <stdio.h>       // printf,scanf
#include <stdlib.h>
#include <math.h>
#include <string>
#include <vector>
#include <algorithm>  //sort,binarySearch
#include <functional> 
#include <iomanip>    // setprecision
#include <utility>    // c+11 Array
#include <set>
#include <sstream>
#include <map>
#include <bits/stdc++.h>
#define MOD 1000000007
#define PI 3.141592653589793238462643383279
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define pb(x) push_back(x)
#define debug(x) cout << #x << " = " << x << endl;
#define debret(x) debug(x) ; return 0;

using namespace std;

int main(){

    int H, W;

    cin >> H >> W;

    char a[H][W];

    REP(i,H){
        REP(j,W){
            cin >> a[i][j];
        }
    }
    int x = 0;
    int y = 0;
    while(y < H-1 || x < W-1){
        
        a[y][x] = '.';
        if((y != H -1) && a[y+1][x] == '#'){
            y++;
        }else if((x != W-1) && a[y][x+1] == '#'){
            x++;
        }else{
            break;
        }
    }
    
    a[y][x] = '.';


    REP(i,H){
        REP(j,W){
            if(a[i][j] == '#'){
                cout << "Impossible" << endl;
                return 0;
            }
        }
    }

    cout << "Possible" << endl;
    return 0;
}
