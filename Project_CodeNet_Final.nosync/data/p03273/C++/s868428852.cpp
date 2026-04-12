#include <bits/stdc++.h>
using namespace std;

int main(){
    int h, w;
    cin >> h >> w;

    vector<string> map(h);
    for (int i = 0; i<h; i++){
        cin >> map.at(i);
    }

    vector<bool> row(h, false);
    vector<bool> column(w, false);

    for (int i = 0; i<h; i++){
        for (int j = 0; j<w; j++){
            if (map.at(i).at(j) == '#'){
                row.at(i) = true;
                break;
            }
        }
    }

    for (int i = 0; i<w; i++){
        for (int j = 0; j<h; j++){
            if (map.at(j).at(i) == '#'){
                column.at(i) = true;
                break;
            }
        }
    }

    for (int i = 0; i<h; i++){
        if (row.at(i)){
            for (int j = 0; j<w; j++){
                if (column.at(j)){
                    cout << map.at(i).at(j);
                }
            }
            cout << endl;
        }
    }

}