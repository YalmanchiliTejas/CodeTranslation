#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<utility>
#include<map>
#include<set>
#include <sstream>
#include<queue>
#include<stack>
#include<functional>
#include<math.h>
#include <iomanip>
using namespace std;


int main(void){
    int h,w;
    cin >> h;
    cin >> w;
    vector< vector<char> > neko;
    vector<char> wl(w,0),hl(h,0);

    for(int y = 0; y < h; y++){
        vector<char> tmp;
        for(int x = 0; x < w; x++){
            char t;
            cin >> t;
            tmp.push_back(t);
            if(t != '.'){
                hl[y]++;
                wl[x]++;
            }
        }
        neko.push_back(tmp);
    }

    for(int y = 0; y < h; y++){
        
        if(hl[y] != 0){
            for(int x = 0; x < w; x++){
                if(wl[x] != 0){
                    cout << neko[y][x];
                }
            }
            cout << endl;
        }
    }
}   