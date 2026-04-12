#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <numeric>
#include <array>
#include <cmath>
#include <memory>
#include <deque>
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
    int n;
    cin >> n;
    deque<int> dq;
    int tmp;
    REP(i,n){
        cin >> tmp;
        if(i%2){
            dq.push_back(tmp);
        }else{
            dq.push_front(tmp);
        }
    }
    if(n%2){
        REP(i,n-1){
            cout << dq.front() << " ";
            dq.pop_front();
        }

        cout << dq.front() << endl;
    }else{
        REP(i,n-1){
            cout << dq.back() << " ";
            dq.pop_back();
        }

        cout << dq.back() << endl;
        
    }

    return 0;
}
