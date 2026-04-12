#include <math.h>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int H, W;
    cin >> H >> W;
    string line;
    vector<vector<char>> MAP(H, vector<char>(W));
    vector<int> tate(W), yoko(H);
    bool flag = true;
    for (int h = 0; h < H;h++){
        cin >> line;
        flag = true;
        for (int w = 0; w < W;w++){
            MAP.at(h).at(w) = line.at(w);
            if (line.at(w)=='#'){
                flag = false;
            }
        }
        if (flag){
            yoko.at(h) = 1;
        }
    }
    for (int w=0;w<W;w++){
        flag=true;
        for (int h=0;h<H;h++){
            if (MAP.at(h).at(w)=='#'){
                flag = false;
                break;
            }
        }
        if (flag){
            tate.at(w)=1;
        }
    }
    for (int h = 0; h < H;h++){
        for (int w = 0; w < W;w++){
            if (tate.at(w)==0 && yoko.at(h)==0){
                cout << MAP.at(h).at(w);
            }
        }
        if (yoko.at(h)==0){
            cout << endl;
        }
    }
}