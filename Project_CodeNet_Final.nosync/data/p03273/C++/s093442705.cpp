#include<iostream>
#include<vector>

using namespace std;

int main(void){

    int h, w;
    cin >> h >> w;

    vector<vector<char>> a(h, vector<char>(w));
    vector<bool> hv, wv;

    for(int i = 0;i < h;i++){
        for(int j = 0;j < w;j++){
            cin >> a[i][j];
        }
    }

    bool flag = true;
    for(int i = 0;i < h;i++){
        for(int j = 0;j < w;j++){
            if(a[i][j] == '#') flag = false;
        }
        if(flag) wv.push_back(true);
        else wv.push_back(false);
        flag = true;
    }

    for(int i = 0;i < w;i++){
        for(int j = 0;j < h;j++){
            if(a[j][i] == '#') flag = false;
        }
        if(flag) hv.push_back(true);
        else hv.push_back(false);
        flag = true;
    }

    flag = true;
    for(int i = 0;i < h;i++){
        for(int j = 0;j < w;j++){
            if(wv[i] == 0 && hv[j] == 0){
                cout << a[i][j];
                flag = false;
            }
        }
        if(!flag) cout << endl;
        flag = true;
    }
    return 0;
}