#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    while(cin >> n){
        if(n==0) break;
        vector<vector<int>> sq(n, vector<int>(n,0));
        int num = 1, x = (n-1)/2, y = (n-1)/2 + 1;
        while(num!=n*n+1){
            if(sq[y][x] != 0){
                x--;
                y++;
            }
            else{
                sq[y][x] = num++;
                x++;
                y++;
            }
            x = (x+n)%n;
            y =(y+n)%n;
        }
        for(int i = 0;i<n;i++){
            for(int j =0;j<n;j++){
                printf("%4d", sq[i][j]);
            }
            cout << endl;
        }
    }
    return 0;
}