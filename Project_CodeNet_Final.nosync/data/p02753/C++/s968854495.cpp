#include <bits/stdc++.h>
#include <string>
#include <vector>
/* 変数i を n回繰り返すマクロ */
#define rep(i,n) for (int i = 0;i < (n);i++)
/* 配列の初期化 fill(array, 0); すべて0に初期化 */
template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){std::fill( (T*)array, (T*)(array+N), val );}
using namespace std;
int main()
{
    string s;

    cin >> s;

    if(s == "AAA" ||s == "BBB"){
        cout << "No" << endl;
    }else{
        cout << "Yes" << endl;;
    }
    return 0;
}