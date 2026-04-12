#include <iostream>
using namespace std;
int main(void){
    // Your code here!
    int h, w;
    int field[100][100] = {{}};
   
    cin >> h >> w;
    for(int i = 0; i < h; i++){
        string temp;
        cin >> temp;
        for(int j = 0; j < w; j++){
            if(temp[j] == '.')
                field[i][j] = 0;
            else
                field[i][j] = 1;
        }
    }
    
    for(int i = 0; i < h; i++){
        int count_white = 0;
        for(int j = 0; j < w; j++)
            if(field[i][j] == 0)
                count_white++;
        if(count_white == w)
            for(int j = 0; j < w; j++)
                field[i][j] = -1;
    }
    
    for(int i = 0; i < w; i++){
        int count_white = 0;
        for(int j = 0; j < h; j++)
            if(field[j][i] == 0 || field[j][i] == -1)
                count_white++;
        if(count_white == h)
            for(int j = 0; j < h; j++)
                field[j][i] = -1;
    }

    for(int i = 0; i < h; i++){
        int count_output = 0;
        for(int j = 0; j < w; j++){
            if(field[i][j] == 0){
                cout << '.';
                count_output++;
            }
            else if(field[i][j] == 1){
                cout << '#';
                count_output++;
            }
        }
        if(count_output > 0)
            cout << endl;
    }
    
    return 0;
    
}
