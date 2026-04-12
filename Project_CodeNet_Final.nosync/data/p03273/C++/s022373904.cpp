#include <bits/stdc++.h>
using namespace std;

int main() {
    int H, W;
    cin >> H >> W;
    vector<string> a(H);
    for(int i = 0; i < H; i++){
        cin >> a.at(i);
    }

    vector<bool> row(H, false); /*falseの意味:該当行の全要素が白*/
    vector<bool> col(W, false); /*falseの意味:該当列の全要素が白*/
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            if(a.at(i).at(j) == '#'){ /*黒を見つけたとき*/
                row.at(i) = true; /*その黒がある行をtrue*/
                col.at(j) = true; /*その黒がある列をtrue*/
            }
        }
    }

    for(int i = 0; i < H; i++){
        if(row.at(i)){ //その行に黒があれば動作を行う
			for(int j = 0; j < W; j++){
				if(col.at(j)){ //その列に黒があれば動作を行う
					cout << a.at(i).at(j);
				}
			}
			cout << endl;
        }
    }
}