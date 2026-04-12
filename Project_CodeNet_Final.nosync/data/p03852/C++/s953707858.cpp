// header file
#include <iostream>
#include <cstdio>
#include <vector>  //vector<T> vec; ランダムアクセスが速い、挿入は線形時間
#include <list>  //list<T> ls; 挿入・消去速い、アクセスは線形時間
#include <algorithm>
#include <functional> // greater<int>()を使える
#include <utility>
#include <string>
#include <map>
// macro
#define REP(i, n) for (int i=0; i < (int)(n); i++)  // 0 ~ n-1
#define REPN(i, n) for (int i=1; i <= (int)(n); i++)  // 1 ~ n
#define R_REP(i, n) for(int i = ((int)(n - 1)); i >= 0; i--)  // Reverse n-1 ~ 0
#define R_REPN(i, n) for(int i= ((int)(n));i > 0;i--)  // Reverse n ~ 1
#define FOR(i, m, n) for(int i = m;i < n;i++)  // 指定範囲loop m ~ n-1
#define pb(vec) push_back(vec)  // 配列の一番うしろに追加
// typedef
typedef long long ll;  // int64

using namespace std;

int main(void) {
    char c;
    cin >> c;
    string str = "aeiou";

    int i = 0;
    while (i <= str.size() - 1){
        if (c == str.at(i)) {
            std::cout << "vowel" << std::endl;
            break;
        }
        // 最後の母音の確認
        if (i == str.size() - 1) {
            if (c == str.at(i)) {
                std::cout << "vowel" << std::endl;
                break;
            } else {
                std::cout << "consonant" << std::endl;
                break;
            }
        }
        i++;
    }
    return 0;
}
