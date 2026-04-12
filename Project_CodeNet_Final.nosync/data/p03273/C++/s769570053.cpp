#include <bits/stdc++.h>
using namespace std;

string s[100];
bool y[100], x[100];

int main(){
    int h, w;
    cin >> h >> w;
    for(int i = 0; i < h; i++) cin >> s[i];
    for(int i = 0; i < h; i++){
        bool f = true;
        for(int j = 0; j < w; j++){
            if(s[i][j] == '#'){
                f = false; break;
            }
        }
        if(f) y[i] = true;
    }
    for(int i = 0; i < w; i++){
        bool f = true;
        for(int j = 0; j < h; j++){
            if(s[j][i] == '#'){
                f = false; break;
            }
        }
        if(f) x[i] = true;
    }
    for(int i = 0; i < h; i++){
        if(y[i]) continue;
        for(int j = 0; j < w; j++){
            if(x[j]) continue;
            cout << s[i][j];
        }
        cout << endl;
    }
}