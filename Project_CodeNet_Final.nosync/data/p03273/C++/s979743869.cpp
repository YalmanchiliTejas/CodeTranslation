#include <iostream>
#include <string>
using namespace std;

int main() {
    int h,w;

    cin >> h >> w;

    string s[h];

    bool flag[h][w];

    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            flag[i][j] = true;
        }
    }

    for(int i=0; i<h; i++){
        cin >> s[i];
    }


    for(int he = 0; he < h; he++){
        bool black_flag = false;
        for(int wi = 0; wi < w; wi++){
            if(s[he][wi] == '#'){
                black_flag = true;
            }
        }
        if(!black_flag){
            for(int wi = 0; wi < w; wi++){
                flag[he][wi] = false;
            }
        }
    }

    for(int wi = 0; wi < w; wi++){
        bool black_flag = false;
        for(int he = 0; he < h; he++){
            if(s[he][wi] == '#'){
                black_flag = true;
            }
        }
        if(!black_flag){
            for(int he = 0; he < h; he++){
                flag[he][wi] = false;
            }
        }
    }

    for(int he=0; he<h; he++){
        bool write_flag = false;
        for(int wi=0; wi<w; wi++){
            if(flag[he][wi]) {
                cout << s[he][wi];
                write_flag = true;
            }
        }
        if(write_flag){
            cout << endl;
        }
    }

    return 0;
}