#include <iostream>
#include <vector>

using namespace std;

int main(void){
    int H, W;
    char a[100][100];
    char sub;
    vector <int> line, low;
    
    cin >> H >> W;
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            cin >> sub;
            a[i][j] = sub;
        }
    }
    
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            if(a[i][j] == '#'){
                line.push_back(i);
                break;
            }
        }
    }
    
    for(int i = 0; i < W; i++){
        for(int j = 0; j < H; j++){
            if(a[j][i] == '#'){
                low.push_back(i);
                break;
            }
        }
    }
    
    for(int i = 0; i < line.size(); i++){
        for(int j = 0; j < low.size(); j++){
            cout << a[line[i]][low[j]];
        }
        cout << endl;
    }
}