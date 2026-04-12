#include <bits/stdc++.h>
#include <string>
#include <vector>
/* 変数i を n回繰り返すマクロ */
#define rep(i,n) for (int i = 0;i < (n);i++)
using namespace std;
int main()
{
    cout << fixed << setprecision(10);//小数点以下10桁出力
    int n,m;
    cin >> n >> m;
    if(n <= m){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}