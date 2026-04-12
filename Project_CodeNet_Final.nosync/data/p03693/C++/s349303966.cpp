#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>  // std::greater<T>()

using namespace std;

// macro
#define ALL(obj) (obj).begin(), (obj).end()
#define REP(i, n) for (int i=0; i < (int)(n); i++)  // 0 ~ n-1
#define DESCEND greater<int>()  // sort 降順
#define UNIQUE(vec) (vec).erase(unique(ALL((vec))), (vec).end());  // 必ずsortを行なってから

// func declaration
template <class T> void printVec(vector<T>);


int main() {
    int r, g, b, num;
    cin >> r >> g >> b;
    num = r*100 + g*10 + b;
    
    if (num % 4 == 0) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    
    return 0;
}

// function
template <class T> void printVec(vector<T> vec) {
    // 1要素ずつ、空白・改行なしで出力
    REP(i, vec.size()) {
        cout << vec.at(i);
    }
    cout << endl;
}
