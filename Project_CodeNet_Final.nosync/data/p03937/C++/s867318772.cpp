#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <map>
#define div 1000000000+7
using namespace std;
typedef long long ll;

int main(){
    int h, w;
    cin >> h >> w;
    char a[h][w];

    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cin >> a[i][j];
        }
    }

    int count = 0;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if(a[i][j] == '#'){
                count++;
            }
        }
    }
    //cout << count << " " << (h+w-1) << endl;
    if(count == (h+w-1)){
        cout << "Possible" << endl;
    }else{
        cout << "Impossible" << endl;
    }

    return 0;
}
