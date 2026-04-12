#include<iostream>
#include<sstream>
#include<vector>
#include<iterator>
using namespace std;

int main(void)
{
    string S;
    cin >> S;

    if (S == "AAA" || S == "BBB")
        cout << "No" << endl;
    else
        cout << "Yes" << endl;

    return 0;
}
