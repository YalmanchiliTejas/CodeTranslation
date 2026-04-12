#include <iostream>
using namespace std;

int grid[100+1][100+1];
int main(){
    int H,W;
    cin >> H >> W;
    for(int h=0;h<H;h++){
        for(int w=0;w<W;w++){
            char a;
            cin >> a;
            if(a=='.'){
                grid[h][w]=0;
            }else{
                grid[h][w]=1;
                grid[h][100]+=1;
                grid[100][w]+=1;
            }
        }
    }

    for(int h=0;h<H;h++){
        int printline=0;
        for(int w=0;w<W;w++){
            if(grid[100][w]>0 && grid[h][100]>0){
                char a='.';
                if(grid[h][w]==1){
                    a='#';
                }
                printline++;
                cout << a;
            }
        }
        if(printline){
            cout << "\n";
        }
    }
    return 0;
}