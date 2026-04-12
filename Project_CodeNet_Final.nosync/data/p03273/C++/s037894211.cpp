#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    int H, W;
    cin >> H >> W;

    vector <string> a(H);
    for (int i = 0; i < H; i++){
        cin >> a[i];
    }

    int counth, countv;
    vector <int> h(0), v(0);
    for (int i = 0; i < H; i++){
        for (int j = 0; j < W; j++){
            if (a[i][j] == '#'){
                counth ++;
            }
        }
        if (counth > 0){
            h.push_back(i);
        }
        counth = 0;
    }
    for (int i = 0; i < W; i++){
        for (int j = 0; j < H; j++){
            if (a[j][i] == '#'){
                countv ++;
            }
        }
        if (countv > 0){
            v.push_back(i);
        }
        countv = 0;
    }

    
    for (int i = 0; i < h.size(); i++){
        for (int j = 0; j < v.size(); j++){
            cout << a[h[i]][v[j]];
        }
        cout << endl;
    }
    
    return 0;
}