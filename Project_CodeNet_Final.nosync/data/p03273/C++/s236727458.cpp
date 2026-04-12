#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
 
int main() {
    int H, W;
    cin >> H >> W;
    vector<string> a(H);
    for(int i=0; i<H; i++){
        cin >> a.at(i);
    }

    vector<bool> gyou(H,false);
    vector<bool> retu(W,false);

    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            if(a.at(i).at(j)=='#'){
                gyou.at(i) = true;
                retu.at(j) = true;
            }
        }
    }
    for(int i=0; i<H; i++){
        if(gyou.at(i)){
            for(int j=0; j<W; j++){
                if(retu.at(j)){
                    cout << a.at(i).at(j);
                }
            }
            cout << endl;
        }
    }
}