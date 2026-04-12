#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>

#define reps(i,s,n) for(int (i) = (s); (i) < (n); (i)++)
#define rep(i,n) reps(i,0,n)
using namespace std;
using ll = long long;

int main(){
    int h,w;
    char map[100][100];
    char copy[100][100];
    char copy2[100][100];
    cin >> h >> w;
    int cnt = 0;
    int H=0;
    char c;
    rep(i,h){
        cnt=0;
        rep(j,w){
            cin >> map[i][j];//y,x
            if(map[i][j] == '#'){
                cnt++;
            }
        }
        if(cnt>0){
            rep(k,w){
                copy[H][k] = map[i][k];
            }
            H++;
        }
    }
    
    int W=0;
    rep(i,w){
        cnt = 0;
        rep(j,H){
            if(copy[j][i] == '#'){
                cnt++;
            }
        }

        if(cnt > 0){
            
            rep(k,H){
                copy2[k][W] = copy[k][i]; 
            }
            W++;
        }
    }

    rep(i,H){
        rep(j,W){
            cout << copy2[i][j];
        }
        cout << endl;
    }

    return 0;
}