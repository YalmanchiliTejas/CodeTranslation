#include <iostream>
using namespace std;
int main()
{
    string s;
    cin >> s;
    cout << (s == "AAA" || s == "BBB" ? "No" : "Yes") << endl;
    return 0;
}