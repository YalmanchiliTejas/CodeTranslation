#include <iostream>
#include <iomanip>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <tuple>
using namespace std;

int main(){

    int h, w; cin >> h >> w;

    int hf = h, wf= w;
    char a[h][w];

    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            cin >> a[i][j];
        }
    }

    set<int> sh;
    for(int i=0; i<h; i++){
        bool allwhite = true;
        for(int j=0; j<w; j++){
            if(a[i][j] == '#'){
                allwhite = false;
                break;
            }
        }
        if(allwhite){
            sh.insert(i);
        }
    }

    set<int> sw;
    for(int j=0; j<w; j++){
        bool allwhite = true;
        for(int i=0; i<h; i++){
            if(a[i][j] == '#'){
                allwhite = false;
                break;
            }
        }
        if(allwhite){
            sw.insert(j);
        }
    }

    for(int i=0; i<h; i++){
        if(sh.find(i) == sh.end()){
            for(int j=0; j<w; j++){
                if(sw.find(j) == sw.end()){
                    cout << a[i][j];
                }
            }
            cout << endl;
        }
    }

    return 0;
}