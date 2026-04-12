#include <bits/stdc++.h>
using namespace std;

int main(){
    int h, w; cin >> h >> w;
    vector<string> s(h);
    vector<bool> gh(h), gw(w);
    for(int i=0; i<h; ++i){cin >> s[i];}
    for(int i=0; i<h; ++i){
        for(int j=0; j<w; ++j){
            if(s[i][j]=='#'){
                gh[i] = true;
                gw[j] = true;
            }
        }
    }
    for(int i=0; i<h; ++i){
        if(!gh[i]){continue;}
        for(int j=0; j<w; ++j){
            if(!gw[j]){continue;}
            cout << s[i][j];
        }
        cout << endl;
    } 
    return 0;
}