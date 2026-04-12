#include <iostream>
#include <iomanip>


using namespace std;


int main(){

    int H, W;
    cin >> H >> W;

    char A[H][W];
    int cnt = 0;
    for (int i = 0; i < H; i++){
        for (int j = 0; j < W; j++){
            cin >> A[i][j];
            if (A[i][j] == '#'){
                cnt++;
            }
        }
    }

    int ans = 1;
    
    bool f = true;
    int i = 0, j = 0;
    while(f == true){
        if (A[i + 1][j] == '#'){
            ans ++;
            i ++;
        }else if(A[i][j + 1] == '#'){
            ans ++;
            j ++;
        }else{
            f = false;
        }
    }
    
    if (ans == cnt){
        cout << "Possible" << endl;
    }else{
        cout << "Impossible" << endl;
    }

    return 0;
}