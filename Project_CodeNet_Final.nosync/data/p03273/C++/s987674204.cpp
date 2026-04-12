using namespace std;

using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
#include <iostream>
#include <string>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <climits>
#include <bitset>
#include <array>
#include <deque>
#include <queue>
#define all(x) (x).begin(),(x).end()

void solve(){

}
int main(){
    int H,W;
    cin >> H >> W;
    vector<bool> row(H,false),col(W,false);
    string a[H];

    for (int i = 0; i < H; i++){
        cin >> a[i];
    }
    for (int i = 0; i < H; i++){
        for (int k = 0; k < W; k++){
            if (a[i][k] == '#'){
                row[i] = true;
                col[k] = true;
            }
        }
    }

    for (int i = 0; i < H; i++){
        if (row[i]){
            for (int k = 0; k < W; k++){
                if (col[k]){
                    cout << a[i][k];
                }
            }
            cout << endl;
        }
    }
    return 0;
}
