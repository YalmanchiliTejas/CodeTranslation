#include <bits/stdc++.h>
using namespace std;

int main() {
    int h, w;
    cin >> h >> w;
    vector<string> v(h), ans;
    int karah[h] = {0}, karaw[w] = {0};
    for(int i = 0; i < h; ++i) cin >> v[i];
    for(int i = 0; i < h; ++i) {
        int dot = 0;
        for(int j = 0; j < w; ++j) {
            if(v[i][j] == '.') dot++;
            else break;
        }
        if(dot == w) karah[i] = 1;
    }
    for(int i = 0; i < w; ++i) {
        int dot = 0;
        for(int j = 0; j < h; ++j) {
            if(v[j][i] == '.') dot++;
        }
        if(dot == h) karaw[i] = 1;
    }
    
    for(int i = 0; i < h; ++i) {
        string a;
        for(int j = 0; j < w; ++j) {
            if(karah[i] == 0 && karaw[j] == 0) {
                a.push_back(v[i][j]);
            }
        }
        if(!a.empty()) ans.push_back(a);
    }
        
    for(int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << '\n';
    }

    return 0;
}
