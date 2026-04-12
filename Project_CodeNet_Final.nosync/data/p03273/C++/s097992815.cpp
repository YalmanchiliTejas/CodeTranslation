#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main(){
    int h, w;
    cin >> h >> w;

    char maze[h][w];

    set<int> ex_x;
    set<int> ex_y;

    for(int y = 0; y < h; y++){
        for(int x = 0; x < w; x++){
            cin >> maze[y][x];
            if(maze[y][x] == '#'){
                ex_x.insert(x);
                ex_y.insert(y);
            }
        }
    }

    for(int y = 0; y < h; y++){
        for(int x = 0; x < w; x++){
            if(ex_x.find(x) != ex_x.end() and ex_y.find(y) != ex_y.end()){
                printf("%c", maze[y][x]);
            }
        }
        if(ex_y.find(y) != ex_y.end()){
            printf("\n");
        }

    }

    


    return 0;


}