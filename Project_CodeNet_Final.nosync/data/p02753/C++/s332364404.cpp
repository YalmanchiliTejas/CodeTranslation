#include<iostream>
using namespace std;
int main()
{
    // スペース区切りの整数の入力
    char str[3];
    cin >> str;

    if (str[0] == str[1] && str[0] == str[2] && str[1] == str[2])
    {
        cout << "No" << endl;
    }else
    {
        cout << "Yes" << endl;
    }


    return 0;
}