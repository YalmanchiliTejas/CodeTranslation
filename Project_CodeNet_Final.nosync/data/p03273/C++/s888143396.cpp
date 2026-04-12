#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i=0;i < (int)(n);i++)

char maze[101][101];
int main(){
    int h,w;
    cin >> h >> w;
    rep(i,h) rep(j,w){
        cin >> maze[i][j];
    }
    for (int i = 0;i < h;i++){
        bool f = true;
        for (int j = 0; j < w;j++){
            if (maze[i][j] != '.') f = false;
        }
        if (f){
            for (int j = 0; j < w;j++){
                maze[i][j] = '+';
            }
        }
    }
    for (int j = 0;j < w;j++){
        bool f = true;
        for (int i = 0;i < h;i++){
            if (maze[i][j] != '.' && maze[i][j] != '+') f = false;
        }
        if (f){
            for (int i = 0;i < h;i++){
                maze[i][j] = '+';
            }
        }
    }
    for (int i = 0;i < h;i++){
        bool f = true;
        int cnt = 0;
        for (int j = 0; j < w;j++){
            if (maze[i][j] != '+'){
                cout << maze[i][j];
            }
            else cnt++;
            if (cnt == w) f = false;
        }
        if (f) {
            cout << endl;
        }
    }
    
    
    return 0;
}