#include<iostream>
#include<vector>//可変長配列
#include<algorithm>//sort,二分探索,など
#include<map>//map(辞書)

using namespace std;

int main(void){
    int x;
    cin >> x;
    if(x >= 30){
        cout << "Yes" << endl;
        return 0;
    }
    cout << "No" << endl;
    return 0;
}