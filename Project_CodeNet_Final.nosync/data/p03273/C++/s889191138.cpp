#include <bits/stdc++.h>
using namespace std;

int main(){
    int h,w;
    cin >> h >> w;
    vector<string> a(h);
    bool tate[w] = {}, yoko[h] = {};
    for(int i = 0; i < h; i++){
        cin >> a[i];
    }
    for(int i = 0;i < h; i++){
        for(int j = 0; j < w; j++){
            if(a[i][j] == '#'){
                yoko[i] = true;
                tate[j] = true;
            }
        }
    }
    for(int i = 0; i < h; i++){
        if(yoko[i]){
            for(int j = 0; j < w; j++){
                if(tate[j]){
                    cout << a[i][j];
                }
            }
            cout << endl;
        }
    }

    return 0;
}
