#include <iostream>
#include <vector>
using namespace std;

int main() {
    int H,W;
    cin >> H >> W;
    vector<vector<char>> mp(H,vector<char>(W));
    int x=0;
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            cin >> mp[i][j];
        }
    }     
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){    
            if(mp[i][j]=='#'){
                if(x>j) {
                    cout << "Impossible" << endl;
                    return 0;
                }else{
                    x=j;
                }
                ;
            }
        }
    }
    cout << "Possible" << endl;
}