#include <iostream>
using namespace std;

int main(void)
{
    string s;
    cin >> s;
    bool flag = false;
    for (int i = 0; i < 2; i++)
    {
        if (s[i] != s[i + 1])
        {
            flag = true;
        }
    }
    if (flag)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    return 0;
}