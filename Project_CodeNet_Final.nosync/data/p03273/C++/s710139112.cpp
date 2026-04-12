#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int h, w;
    cin >> h >> w;

    vector<string> board(h);

    for (int i = 0; i < h; i++){
        cin >> board.at(i);
    }
    vector<bool> row(h, false);
    vector<bool> col(w, false);
    for (int i = 0; i < h; i++){
        for (int j = 0; j < w; j++){
            if (board.at(i).at(j) == '#'){
                row.at(i) = true;
                col.at(j) = true;
            }
        }
    }
    int cnt;
    for (int i = 0; i < h; i++){
        cnt = 0;
        if(row.at(i)){
            for (int j = 0; j < w; j++){
                if (col.at(j)){
                    cout << board.at(i).at(j);
                    cnt++;
                }
            }
        }
    if(cnt!=0)
        cout << endl;
    }
    return 0;
}