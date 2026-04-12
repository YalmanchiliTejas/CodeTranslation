#include <bits/stdc++.h>
using namespace std;

char a[10][10];

int main(){
    int h, w;
    cin >> h >> w;
    for(int i = 0;i < h;i++){
        cin >> a[i];
    }

    int i = 0, j = 0;
    while(1){
        a[i][j] = '.';
        if(i == h-1 && j == w-1){
            break;
        }

        if(a[i][j+1] == '#'){
            j++;
        }else if(a[i+1][j] == '#'){
            i++;
        }else{
            break;
        }
    }

    for(int i = 0;i < h;i++){
        for(int j = 0;j < w;j++){
            if(a[i][j] == '#'){
                cout << "Impossible" << endl;
                return 0;
            }
        }
    }

    cout << "Possible" << endl;

    return 0;
}




