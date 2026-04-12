#include<iostream>
using namespace std;
int main()
{
    int h, w;
    bool c[8][8];
    char ch;
    cin >> h >> w;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cin >> ch;
            c[i][j] = (ch == '#');
        }
    }
    for(int i = 0; i < h-1; i++){
        for(int j = 0; j < w-1; j++){
            if(c[i][j+1] == 1 && c[i+1][j] == 1){
                cout << "Impossible" << endl;
                return 0;
            }
        }
    }
    cout << "Possible" << endl;
    return 0;
}