#include <iostream>
#include <string>
using namespace std;

int H,W;
char A[10][10];

int nx,ny;
int gx,gy;

int main(){
    nx = 1;ny = 1;

    cin >> H >> W;
    for(int y = 1;y < H+1;y++){
        for(int x = 1;x < W+1;x++){
            cin >> A[x][y];
        }
    }

    gx = W;gy = H;
    A[1][1] = 'f';

    while(1){
 //       cout << nx << "," << ny << endl;

        if(A[nx+1][ny] == '#'){
            A[nx+1][ny] = 'f';
            nx = nx + 1;
            continue;
        }

        if(A[nx][ny+1] == '#'){
            A[nx][ny+1] = 'f';
            ny = ny + 1;
            continue;
        }

        break;
    }

    /*for(int y = 1;y < H+1;y++){
        cout << endl;
        for(int x = 1;x < W+1;x++){
            cout << A[x][y];
        }
    }*/

    for(int y = 1;y < H+1;y++){
        for(int x = 1;x < W+1;x++){

            if(A[x][y] == '#'){
                cout << "Impossible" << endl;
                exit(0);
            }

        }
    }

    cout << "Possible" << endl;
}