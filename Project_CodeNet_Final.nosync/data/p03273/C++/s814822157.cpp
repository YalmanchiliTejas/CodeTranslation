#include <bits/stdc++.h>
using namespace std;
int main(){
    int h, w;
    cin >> h >> w;
    vector<string> table(h);
    vector<bool> h_white(h, true);
    vector<bool> w_white(w, true);
    for (int i = 0; i < h; i++){
        cin >> table[i];
    }
    
    for (int i = 0; i < h; i++){
        for (int j = 0; j < w; j++){
            string str = table[i];
            if(str[j] == '#'){
                h_white[i] = false;
                break;
            }
        }
    }
    
    for (int j = 0; j < w; j++){
        for (int i = 0; i < h; i++){
            string str = table[i];
            if(str[j] == '#'){
                w_white[j] = false;
                break;
            }
        }
    }
    
    for (int i = 0; i < h; i++){
        if(h_white[i]) continue;
        string str = table[i];
        for (int j = 0; j < w; j++){
            if(w_white[j])continue;
            cout << str[j];
        }
        cout << endl;
    }
}