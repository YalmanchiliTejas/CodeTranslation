#include <bits/stdc++.h>
using namespace std;

main(){
    int H,W;
    cin >> H >> W;
    vector<vector<char>> grid(H,vector<char>(W));
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            cin >> grid.at(i).at(j);
        }
    }

    vector<bool> lineall(H,0), rowall(W,0);

    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            if(grid.at(i).at(j)=='#'){
                lineall.at(i) = 1;
                break;
            }
        }
    }
    for(int i=0;i<W;i++){
        for(int j=0;j<H;j++){
            if(grid.at(j).at(i)=='#'){
                rowall.at(i) = 1;
                break;
            }
        }
    }

    for(int i=0;i<H;i++){
        if(lineall.at(i)==1){
            for(int j=0;j<W;j++){
                if(rowall.at(j)==1){
                    cout << grid.at(i).at(j);
                }
            }
            cout<<endl;
        }
    }
}


