#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main() {

    int H, W;
    cin >> H >> W;

    vector<vector<string>> table(H, vector<string>(W));

    vector<int> del_i;
    vector<int> del_j;


    for (int i = 0; i < H; i++) {
        //cin >> A.at(i) >> B.at(i);
        string line;
        cin >> line;

        for (int j = 0; j < line.size(); j++) {
            table.at(i).at(j) = line.substr(j,1);
        }

    }
    ///////////////////////////////
    for (int i = 0; i < H; i++) {
        bool flg = true;
        for (int j = 0; j < W; j++) {
            if(table.at(i).at(j) == "#"){
                flg = false;
            }
        }
        if(flg){
            // del i idx
            //cout << "del i: " << i <<endl;
            del_i.push_back(i);
        }
    }

    ///////////////////////////////
    for (int j = 0; j < W; j++) {
        bool flg = true;
        for (int i = 0; i < H; i++) {

            if(table.at(i).at(j) == "#"){
                flg = false;
            }
        }
        if(flg){
            // del j idx
            //cout << "del j: " << j <<endl;
            del_j.push_back(j);     
        }
    }

    vector<vector<string>> new_table(vector<string>);

    for (int i = 0; i < H; i++) {

        bool di_flg = false;
        for (int di = 0; di < del_i.size(); di++) {
            if(i == del_i.at(di)){
                di_flg = true;
                break;
            }
        }
        if (di_flg){
            continue;
        }

        

         for (int j = 0; j < W; j++) {
             //cout << table.at(i).at(j);

            bool dj_flg = false;
            for (int dj = 0; dj < del_j.size(); dj++) {
                if(j == del_j.at(dj)){
                    dj_flg = true;
                    break;
                }
            }
            if (dj_flg){
                continue;
            }

            cout << table.at(i).at(j);


         }
         cout << endl;
    }






    // for (int i = 0; i < M; i++) {
    //     //cin >> A.at(i) >> B.at(i);
    //     int kachi = A.at(i) - 1;
    //     int make  = B.at(i) - 1; 

    //     table.at(kachi).at(make) = "o";
    //     table.at(make).at(kachi) = "x";
    // }

    // for (int i = 0; i < H; i++) {
    //     for (int j = 0; j < W; j++) {
    //         cout << table.at(i).at(j);
    //     }
    //     cout << endl;
    // }

}
