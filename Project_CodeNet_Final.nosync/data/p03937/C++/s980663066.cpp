#include <iostream>
#include <cstdio>
using namespace std;

char maze[8][8];


int h, w;


int main(){
    cin >> h >> w;

    int count = 0;
    for(int y = 0; y < h; y++){
        for(int x = 0; x < w; x++){
            cin >> maze[y][x];
            if(maze[y][x] == '#'){
                count++;
            }
        }
    }



    if(count != h+w-1){
        printf("Impossible\n");
    }
    else{
        printf("Possible\n");
    }

    return 0;

}