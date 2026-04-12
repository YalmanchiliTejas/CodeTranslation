#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i=0;i < (int)(n);i++)

char maze[101][101];
int main(){
    int h,w;
    cin >> h >> w;
    rep(i,h) rep(j,w) {
        cin >> maze[i][j];
    }
    rep(i,h){
        bool all = true;
        rep(j,w){
            if (maze[i][j] != '.') {
                all = false;
                break; 
            }    
        }
        if (all){ 
            rep(q,w) maze[i][q] = 'x';
        }
    }
    rep(i,w){
        bool all = true;
        rep(j,h){
            if (maze[j][i] != '.' && maze[j][i] != 'x') {
                all = false;
                break; 
            }
        }
        if (all){
            rep(q,h) maze[q][i] = 'x';
        }
    }
    rep(i,h){
        bool yes = false;
        rep(j,w){
            if (maze[i][j] == 'x') continue;
            else {
                cout << maze[i][j];
                yes = true;
            }
        }
        if (yes) cout << endl;
    }


    
    
    return 0;
}