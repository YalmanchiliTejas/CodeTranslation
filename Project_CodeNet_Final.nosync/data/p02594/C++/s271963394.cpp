#include <bits/stdc++.h>
using namespace std;
#define rep(i, N) for (int i = 0; i < (N); i++)  

int main()
{
    // 入力
    int X;
    string result;
    cin >> X;

    // 計算
    if (X >= 30){
        result = "Yes";
    } else {
        result = "No";
    }
    


    // 出力
    cout << result << endl;
    return 0;  
}
