#include <bits/stdc++.h>
using namespace std;

int main() {
    int h,w;
    cin >> h >> w;
    vector<vector<char>> a(h, vector<char>(w));
    for(int i = 0; i < h; i++)
    {
        for(int j = 0; j < w; j++)
        {
            cin >> a.at(i).at(j);
        }
        
    }
    vector<bool> all_empty_h(h,false);
    vector<bool> all_empty_w(w,false);
    for(int i = 0; i < h; i++)
    {
        for(int j = 0; j < w; j++)
        {
            if (a.at(i).at(j) == '#') break;
            else if (j == w - 1) {
                all_empty_h.at(i) = true;
            }
        }
    }
    for(int i = 0; i < w; i++)
    {
        for(int j = 0; j < h; j++)
        {
            if (a.at(j).at(i) == '#') break;
            else if (j == h - 1) {
                all_empty_w.at(i) = true;
            }
        }
    }
    
    bool flag;
    for(int i = 0; i < h; i++)
    {
        if (all_empty_h.at(i)) continue;
        flag = false;
        for(int j = 0; j < w; j++)
        {
            if (all_empty_w.at(j)) continue;
            else {
                cout << a.at(i).at(j);
                flag = true;
            }
        }
        if (flag) cout << endl;
    }
    
    
}