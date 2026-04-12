#include <iostream>
#include <string>

using namespace std;

int main(){
    int H, W;
    cin >> H >> W;

    string lastrow = "null";
    int lmaxcpos = -1;
    for(int i = 0; i < H; i++){
        string crow;
        cin >> crow;
        int tmaxcpos;
        for(int j = 0; j < crow.length(); j++){
            if(lmaxcpos != -1 && j < lmaxcpos && crow[j] == '#')
                goto impossible;
            if(crow[j] == '#')
                tmaxcpos = j;
        }
        lmaxcpos = tmaxcpos;
    }
    cout << "Possible";
    return 0;
    
    impossible:
    cout << "Impossible";
    return 0;
}