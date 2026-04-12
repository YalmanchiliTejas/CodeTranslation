#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

 
int main() {
    int H, W;
    cin >> H >> W;
    vector<vector<char>> masu(H, vector<char> (W));

    for(int i=0 ; i<H ; i++){
        for(int j=0 ; j<W ; j++){
            cin >> masu.at(i).at(j);
        }
    }

    vector<bool> row(H);
    vector<bool> col(W);

    for(int i=0 ; i<H ; i++){
        bool flag = false;
        for(int j=0 ; j<W ; j++){
            if(masu.at(i).at(j)=='#'){flag=true; break;}
        }
        row.at(i) = flag;
    }

    for(int j=0 ; j<W ; j++){
        bool flag = false;
        for(int i=0 ; i<H ; i++){
            if(masu.at(i).at(j)=='#'){flag=true; break;}
        }
        col.at(j) = flag;
    }

    for(int i=0 ; i<H ; i++){
        for(int j=0 ; j<W ; j++){
            if(row.at(i) && col.at(j)){cout << masu.at(i).at(j);}
        }
        if(row.at(i)){cout << endl;}
    }
}
