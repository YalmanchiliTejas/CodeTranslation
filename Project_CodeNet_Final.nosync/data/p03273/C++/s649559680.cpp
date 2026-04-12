#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    int x, y;
    cin >> x >> y;
    char z[100][100];
    for(int a = 0; a < x; a++){
        for(int b = 0; b < y; b++) cin >> z[a][b]; 
    }

    bool ans[2][100] = {false};
    for(int c = 0; c < x; c++){
        for(int d = 0; d < y; d++){
            if(z[c][d] == '#') break;
            if(d == y - 1) ans[0][c] = true;
        }
    }
    for(int c = 0; c < y; c++){
        for(int d = 0; d < x; d++){
            if(z[d][c] == '#') break;
            if(d == x - 1) ans[1][c] = true;
        }
    }

    for(int e = 0; e < x; e++){
        if(ans[0][e] == false){
            for(int f = 0; f < y; f++){
                if(ans[1][f] == false) cout << z[e][f];
            }
            cout << endl;
        }
    }
    return 0;
}