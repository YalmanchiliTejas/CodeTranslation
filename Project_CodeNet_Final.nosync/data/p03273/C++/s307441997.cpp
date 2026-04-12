/*
これを入れて実行
g++ code.cpp
./a.out
 */

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <utility>
#include <set>
#include <map>
#include <cmath>
#include <tuple>
#include <iomanip>

using namespace std;
typedef long long ll;
typedef long double ld;

int dy[4] = {-1, 0, +1, 0};
int dx[4] = {0, +1, 0, -1};

const long long INF = 1LL << 60;
const ll MOD = 1e9 + 7;

bool greaterSecond(const pair<int, int>& f, const pair<int, int>& s){
    return f.second > s.second;
}

int gcd(int a, int b){
	if (b == 0)return a;
	return gcd(b, a % b);
}

//-----------------------ここから-----------


int main(void){
    int h, w;
    cin >> h >> w;

    vector<string> a;
    for(int i = 0; i < h; i++){
        string tmp;
        cin >> tmp;
        a.push_back(tmp);
    }

    vector<int> delindexH;

    for(int i = 0; i < h; i++){
        bool candel = true;
        for(int j = 0; j < w; j++){
            if(a[i][j] == '#'){
                candel = false;
                break;
            }
        }
        if(candel){
            // cout << i << endl;
           delindexH.push_back(i);
        }
    }

    vector<int> delindexW;

    for(int i = 0; i < w; i++){
        bool candel = true;
        for(int j = 0; j < h; j++){
            if(a[j][i] == '#'){
                candel = false;
                break;
            }
        }
        if(candel){
            // cout << i << endl;
            delindexW.push_back(i);
        }
    }

   

    for(int i = 0; i < h; i++){
        bool okH = true;
        bool showed = false;
        for(int j = 0; j < delindexH.size(); j++){
            if(i == delindexH[j]){
                okH = false;
                break;
            }
        }

        for(int j = 0; j < w; j++){
            bool okW = true;
            for(int k = 0; k < delindexW.size(); k++){
                
                if(j == delindexW[k]){
                    okW = false;
                    break;
                }
            }

            if(okH && okW){
                cout << a[i][j];
                showed = true;
            }
        }

        if(showed)cout << endl;

    }



}

