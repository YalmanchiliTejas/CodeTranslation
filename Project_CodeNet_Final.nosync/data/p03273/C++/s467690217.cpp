//ABC107B_Grid_Compression
#include <iostream>
#include<algorithm>
using namespace std;

int main() {
    int H, W;
    cin >> H >> W;
    char a[H][W];

    for (int i = 0;i < H;i++){
        for(int j = 0; j < W;j++){
            cin >> a[i][j];
        }
    }

    char b[H][W];
    bool flag;
    int k = 0;

    for (int i = 0;i < H;i++){
        flag = true;
        for(int j = 0; j < W;j++){
            if(a[i][j] == '#'){
                flag = false;
            }
        }
        if (!flag){
            for(int l = 0; l < W; l++){
                b[k][l] = a[i][l];
            }
            k++;
        }
    }

    int K = k;
    char c[K][W];
    int l = 0;

    for(int j = 0; j < W ; j ++){
        flag = true;
        for(int i = 0; i < K; i++){
            if (b[i][j] == '#'){
                flag = false;
            }
        }

        if(!flag){
            for (int q = 0; q < K; q++){
                c[q][l] = b[q][j];
            }
            l++;
        }
    }

    int L = l;
    for(int i = 0; i < K;i++){
        for(int j = 0; j < L ;j++){
            cout << c[i][j];
        }
        cout << endl;
    }
	return 0;
}