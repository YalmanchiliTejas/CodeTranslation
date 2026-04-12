#include <bits/stdc++.h>
using namespace std;

int main()
{
    char c;
    cin >> c;
    string v = "aeiou";
    int f = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (c == v.at(i))
        {
            f = 1;
            break;
        }
    }
    if (f == 1)
        cout << "vowel" << endl;
    else
        cout << "consonant" << endl;
}
