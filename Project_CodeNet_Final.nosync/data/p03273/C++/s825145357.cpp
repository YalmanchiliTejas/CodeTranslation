#include <bits/stdc++.h>
using namespace std;

int main() {
    int h,w;
    cin >> h >> w;
    vector<vector<char>> a(h , vector<char>(w));
    vector<bool> h_det(h),w_det(w);
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cin >> a.at(i).at(j);
        }
    }
    int h_a = h;
    int w_a = w;

    for(int i = 0; i < h; i++){
        bool det = false;
        for(int j = 0; j < w; j++){
            if(a.at(i).at(j) == '#')det = true;
        }
        h_det.at(i) = det;
    }
    for(int i = 0; i < w; i++){
        bool det = false;
        for(int j = 0; j < h; j++){
            if(a.at(j).at(i) == '#')det = true;
        }
        w_det.at(i) = det;
    }

    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if(h_det.at(i) && w_det.at(j))cout << a.at(i).at(j);
        }
        if(h_det.at(i))cout << endl;
    }
}
