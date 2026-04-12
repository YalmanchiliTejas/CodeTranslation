#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <numeric>
#include <array>
#include <cmath>
#include <memory>
using namespace std;
//変数デバッグ
#define DEB(variable) cout << #variable << '=' << variable << endl

//for簡易表記(引数ミス防止)
#define FOR(LoopVariable,numberOFbegin,numberOFend) for (int LoopVariable = (numberOFbegin); (LoopVariable) < (numberOFend); (LoopVariable)++)
#define DEFOR(LoopVariable,numberOFbegin,numberOFend) for (int LoopVariable = (numberOFbegin)-1; (LoopVariable) >= (numberOFend); (LoopVariable)--)
#define REP(LoopVariable,numberOFend) for(int LoopVariable = 0;(LoopVariable)<(numberOFend);LoopVariable++)

constexpr long long int linf = numeric_limits<long long int>::max()-5;
constexpr int inf= numeric_limits<int>::max()-5;
constexpr long long int mod = 1000000007;

int main(){

    int h, w;
    cin >> h >> w;
    vector<string> vs(h);

    REP(i,h){
        cin >> vs[i];
    }

    vector<bool> vh(h, false), vw(w, false);

    

    REP(i,h){
        REP(j,w){
            if(vs[i][j]=='#'){
                vh[i]=true;
                vw[j] = true;
            }
        }
    }
    bool endl_f;
    REP(i,h){
        endl_f = false;
        REP(j,w){
            if(vh[i]&&vw[j]){
                cout << vs[i][j];
                endl_f = true;
            }
        }
        if(endl_f){
            cout << endl;
        }
    }

    return 0;
}
