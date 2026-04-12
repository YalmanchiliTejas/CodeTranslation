#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <numeric>
#include <array>
#include <cmath>
#include <map>
using namespace std;
//変数デバッグ
#define DEB(variable) cout << #variable << '=' << variable << endl

//for簡易表記(引数ミス防止)
#define FOR(LoopVariable,numberOFbegin,numberOFend) for (int LoopVariable = (numberOFbegin); (LoopVariable) < (numberOFend); (LoopVariable)++)
#define DEFOR(LoopVariable,numberOFbegin,numberOFend) for (int LoopVariable = (numberOFbegin); (LoopVariable) > (numberOFend); (LoopVariable)--)
#define REP(LoopVariable,numberOFend) for(int LoopVariable = 0;(LoopVariable)<(numberOFend);LoopVariable++)

constexpr long long int linf = numeric_limits<long long int>::max()-5;
constexpr int inf= numeric_limits<int>::max()-5;
constexpr long long int mod = 1000000007;

int main(){

    int n;
    cin >> n;
    string tmps;
    map<char, int> result,tmpmp;
    for (char c = 'a'; c <= 'z';c++){
        result[c] = 0;
    }
        cin >> tmps;
    for(char &s:tmps){
        result[s]++;
    }
    FOR(i,1,n){
        cin >> tmps;
        for (char c = 'a'; c <= 'z';c++){
            tmpmp[c] = 0;
        }
        for(char &s:tmps){
            tmpmp[s]++;
        }
        for (char c = 'a'; c <= 'z';c++){
            result[c] = min(result[c],tmpmp[c]);
        }
    }
    for (char c = 'a'; c <= 'z';c++){
        REP(i,result[c]){
            printf("%c", c);
        }
    }
    printf("\n");
    return 0;
}
