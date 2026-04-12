#include<iostream>
#include<vector>
#include<algorithm>
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;

int main(){
    int H, W;
    cin >> H >> W;

    vector<vector<char> > table(H,vector<char>(W));
    
    rep(i,H){
        rep(j,W){
            cin >> table.at(i).at(j);
        }
    }

    bool flag;
    // row
    rep(i,H){

        flag = true;
        rep(j,W){
            if(table.at(i).at(j) == '#') flag = false;
        }
        if(flag) {
            // delete row i
            // table.erase(table.at(i).begin());
            table.erase(table.begin()+i);
            i--;
            H--;
        }
    }

    //column
    rep(j,W){
        flag = true;
        rep(i,H){
            if(table.at(i).at(j) == '#') flag = false;
        }
        if(flag) {
            // delete column j
            rep(i,H){
                table.at(i).erase(table.at(i).begin()+j);
            }
            j--;
            W--;
        }
    }

    //output
    rep(i,H){
        rep(j,W){
            cout << table.at(i).at(j);
        }
        cout << endl;
    }

    return 0;
}