#include <iostream>
#include <string>
#include <stdio.h>
#include <cmath>
#include <cfloat>
#include <algorithm>
#include <numeric>
#include <vector>
#include <iterator>
#include <set>
#include <map>
using namespace std;

const double PI=acos(-1);

int main(){
    long h, w;
    cin >> h >> w;
    long wh = 0, bl = 0;
    vector<string> ss;
    for(int i = 0; i < h; i++){
        string s;
        cin >> s;
        ss.push_back(s);
    }
    vector<long> he, we;
    for(int i = 0; i < ss.size(); i++){
        for(int j = 0; j < w; j++){
            if(ss[i][j] == '.') wh++;
            else bl++;
        }
        if(bl == 0) we.push_back(i);
        wh = bl = 0;
    }
    for(int i = 0; i < w; i++){
        for(int j = 0; j < ss.size(); j++){
            if(ss[j][i] == '.') wh++;
            else bl++;
        }
        if(bl == 0) he.push_back(i);
        wh = bl = 0;
    }
    for(int j = 0; j < ss.size(); j++){
        bool z = false;
        for(int i = 0; i < w; i++){
            if(find(we.begin(), we.end(), j) == we.end() && find(he.begin(), he.end(), i) == he.end()){
                cout << ss[j][i];
                z = true;
            }
        }
        if(z) cout << endl;
    }
    return 0;
}