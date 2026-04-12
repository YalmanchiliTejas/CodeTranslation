#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main(){
    int h, w;
    cin >> h >> w;
    vector<vector<string>> mas(h, vector<string>(w));

    int index = 0;
    for(int i = 0; i < h; i++){
        string tmp;
        cin >> tmp;
        for(int j = 0;j < w; j++){
            mas[index][j] = tmp[j];
        }
        index++;
    }

    for(int i = 0; i < h; i++){
         bool flag = true;
        for(int j = 0; j < w; j++){
            if(mas[i][j] == "#"){
                flag = false;
                break;
            }
        }
        if(flag){
            for(int j = 0; j < w; j++){
                mas[i][j] = '+';
            }
        }
    }

    for(int i = 0; i < w; i++){
        bool flag = true;
        for(int j = 0; j < h; j++){
            if(mas[j][i] == "#"){
                flag = false;
                break;
            }
        }
        if(flag){
            for(int j = 0; j < h; j++){
                mas[j][i] = '+';
            }
        }
    }

    for(int i = 0; i < h; i++){
        bool flag = true;
        for(int j = 0; j < w; j++){
            if(mas[i][j] != "+"){
                flag = false;
                cout << mas[i][j];
            }
        }
        if(!flag){
            cout << endl;
        }
    }

    return 0;
}