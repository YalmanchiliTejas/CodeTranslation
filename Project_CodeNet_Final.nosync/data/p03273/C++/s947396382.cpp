#include <iostream>
#include <string>
#include <algorithm>
#include <utility>
#include <iomanip>
#include <functional>
#include <queue>
#include <stack>
#include <map>
#include <vector>
#include <cmath>
#include <cctype>
#include <cstdio>
#define ll long long
#define INF 1e+18
#define MOD 1000000007
using namespace std;



int main(){
    int H,W;
    cin >> H >> W;
    char matrix[100][100];
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            cin >> matrix[i][j];
        }
    }
    
    for(int i=0; i<H; i++){
        int f=1;
        for(int j=0; j<W; j++){
            if(matrix[i][j] == '#') f=0;
        }
        if(f){
            for(int j=0; j<W; j++){
                matrix[i][j] = '!';
            }
        }
    }
    
    for(int j=0; j<W; j++){
        int f=1;
        for(int i=0; i<H; i++){
            if(matrix[i][j] == '#') f=0;
        }
        if(f){
            for(int i=0; i<H; i++){
                matrix[i][j] = '!';
            }
        }
    }
    
    for(int i=0; i<H; i++){
        int f=1;
        for(int j=0; j<W; j++){
            if(matrix[i][j]!='!'){
                f=0;
                cout<<matrix[i][j];
            }
        }
        
        if(!f)cout<<endl;
    }
    return 0;
}
