#include <iostream>
#include <string>

using namespace std;

int H, W;
string s[101];

int main() {

        cin >> H >> W;

        for(int i = 0; i < H; i++)
            cin >> s[i];

        bool white[100][100] = {false};
    
        for(int i = 0; i < H; i++){
            
            bool can = true;

            for(int j = 0; j < W; j++){

                if(s[i][j] == '#'){
                    can = false;
                    break;
                }
            }

            if(can){
                for(int k = 0; k < W; k++){
                    white[i][k] = true;
                }
            }
        }

    
        for(int i = 0; i < W; i++){
            
            bool can = true;

            for(int j = 0; j < H; j++){

                if(s[j][i] == '#'){
                    can = false;
                    break;
                }
            }

            if(can){
                for(int k = 0; k < H; k++){
                    white[k][i] = true;
                }
            }
        }

       

        for(int i = 0; i < H; i++){
            int out = 0;
            for(int j = 0; j < W; j++){
                if(!white[i][j]){
                    cout << s[i][j];
                    out++;
                }
            }
            if(out)
                cout << '\n';
        }

}

