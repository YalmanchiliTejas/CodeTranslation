#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <numeric>
#include <cmath>
using namespace std;
//変数デバッグ
#define DEB(variable) cout << #variable << '=' << variable << endl

//for簡易表記(引数ミス防止)
#define FOR(LoopVariable,numberOFbegin,numberOFend) for (int LoopVariable = (numberOFbegin); (LoopVariable) < (numberOFend); (LoopVariable)++)
#define REP(LoopVariable,numberOFend) for(int LoopVariable = 0;(LoopVariable)<(numberOFend);LoopVariable++)


int main(){

    long long int n, x;
    cin >> n >> x;
    long long int result=0,finder=0;
    bool upperflag = 1;
    for (int i = n+1 ; i > 0;i--){
        finder += ((!upperflag)*(-1)+(upperflag))*((long long int)pow(2, i) - 1);
        if(x==finder){
            result += (long long int)pow(2, i-1);
            break;
        }else if(x>finder){
            upperflag = true;
            result += (long long int)pow(2, i-1);
        }else{
            upperflag = false;
        }
    }
    cout << result << endl;
    return 0;
}