#include<iostream>
#include<cstdio>
#include<string>
#include<cmath>
#include<algorithm>
#include<utility>
#include<vector>
#include<climits>
#include<queue>
#include<random>

#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;


int h,w;

int main(int argc, char const *argv[]) {


    cin >> h >> w;
    vector<string> field(h);
    vector<string> out(h);

    bool row[h];
    bool column[w];
    rep(i,h) row[i] = false;
    rep(i,w) column[i] = false;
    rep(i,h){
        cin >> field[i];
    }
    // rep(i,h){
    //     cout <<  field[i];
    //     cout << endl;
    // }
    for(int i=0;i<h;i++){
        bool all_white = true;
        for(int j=0;j<w;j++){
            if(field[i][j] != '.'){
                all_white = false;
            }
        }
        if(all_white){
            row[i] = true;
        }
    }

    for(int i=0;i<w;i++){
        bool all_white = true;
        for(int j=0;j<h;j++){
            if(field[j][i] != '.'){
                all_white = false;
            }
        }
        if(all_white){
            column[i] = true;
        }
    }
    //rep(i,h)cout << row[i] << endl;
    //cout << endl;
    //rep(i,w)cout << column[i] << endl;
    int index=0;
    for(int i=0;i<h;i++){
        if(!row[i]){
            string str="";
            for(int j=0;j<w;j++){
                if(!column[j]){
                    str+=field[i][j];
                }
            }
            out[index] = str;
            index++;
        }
    }
    rep(i,index){
        cout << out[i];
        cout << endl;
    }
    return 0;
}
