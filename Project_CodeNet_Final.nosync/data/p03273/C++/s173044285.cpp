#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cmath>
#include <iomanip>
#include <algorithm>
using namespace std;

int main(){
    int h, w;
    cin >> h >> w;
    char a[h][w];
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cin >> a[i][j];
        }
    }
    while(true){
        bool flag = false;
        for(int i = 0; i < h; i++){
            int white = 0;
            int deleted = 0;
            for(int j = 0; j < w; j++){
                if(a[i][j] == '.'){
                    white++;
                } else if(a[i][j] == '-'){
                    deleted++;
                }
            }
            if(white + deleted == w && deleted != w){
                for(int j = 0; j < w; j++){
                    a[i][j] = '-';
                }
                flag = true;
            }
        }

        for(int i = 0; i < w; i++){
            int white = 0;
            int deleted = 0;
            for(int j = 0; j < h; j++){
                if(a[j][i] == '.'){
                    white++;
                } else if(a[j][i] == '-'){
                    deleted++;
                }
            }
            if(white + deleted == h && deleted != h){
                for(int j = 0; j < h; j++){
                    a[j][i] = '-';
                }
                flag = true;
            }
        }
        if(!flag){
            break;
        }
    }

    for(int i = 0; i < h; i++){
        int count = 0;
        for(int j = 0; j < w; j++){
            if(a[i][j] != '-'){
                cout << a[i][j];
                count++;
            }
        }
        if(count != 0){
            cout << endl;
        }
    }
    return 0;
}
