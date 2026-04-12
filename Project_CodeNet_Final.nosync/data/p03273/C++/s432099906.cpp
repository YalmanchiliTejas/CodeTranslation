#include<bits/stdc++.h>
using namespace std;
int main() {
    int H,W;cin>>H>>W;
    vector<vector <char>> a(H,vector<char>(W));

    for(int i=0;i<H;i++){//入力
        for(int j=0;j<W;j++){//入力
            cin>>a.at(i).at(j);
        }
    }

    vector<bool> row(H,false),column(W,false);

    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++) {
            if (a[i][j] == '#') {
                row[i]=true;
                column[j]=true;
            }
        }
    }

    for(int i=0;i<H;i++) {
        if (row[i] == true) {
            for (int j = 0; j < W; j++) {
                if (column[j] == true) {
                    cout << a[i][j];
                }
            }
        }
        cout<<endl;
    }
    return 0;
}