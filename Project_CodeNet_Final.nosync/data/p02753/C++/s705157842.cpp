#include<iostream>
using namespace std;
int main()
{
    string s;
    cin >> s;
    // 出力
    
    if (s == "AAA" || s == "BBB") {
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    return 0;
}