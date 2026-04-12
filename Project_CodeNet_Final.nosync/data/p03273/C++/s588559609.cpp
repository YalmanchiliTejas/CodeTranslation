#include <iostream>
//#include <iomanip>
//#include <algorithm>
//#include <numeric>
//#include <queue>
//#include <stack>
//#include <math.h>
#include <vector>
//#include <string>
//typedef long long LL;
using namespace std;

int main(){
    int h;
    int w;
    char tmp_a;
    int f_h=0;
    int f_w=0;
    bool skip_hw;
    cin >> h >> w;
    vector<vector<char>> a(h, vector<char>(w));
    vector<vector<char>> a_h(h, vector<char>(w));
    vector<vector<char>> a_w(h, vector<char>(w));
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            cin >> tmp_a;
            a[i][j]=tmp_a;
        }
    }

    for(int j=0; j<w; j++){
        skip_hw=true;
        for(int i=0; i<h; i++){
            if(a[i][j]=='#'){
                skip_hw=false;
            }
        }
        if(skip_hw==false){
            for(int i=0; i<h; i++){
                a_w[i][f_w]=a[i][j];
            }
            f_w++;
        }
    }

    for(int i=0; i<h; i++){
        skip_hw=true;
        for(int j=0; j<f_w; j++){
            if(a_w[i][j]=='#'){
                skip_hw=false;
            }
        }
        if(skip_hw==false){
            for(int j=0; j<f_w; j++){
                a_h[f_h][j]=a_w[i][j];
            }
            f_h++;
        }
    }
    //cout << f_h << " " << f_w << endl;

    for(int i=0; i<f_h; i++){
        for(int j=0; j<f_w; j++){
            cout << a_h[i][j];
        }
        cout << endl;
    }
}
