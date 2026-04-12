#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    char AB[3] = "AB";

    cin >> s;

    int n_a = 0;
    int n_b = 0;
    for(int i=0; i<s.size(); i++)
    {
        if(s[i] == AB[0])
        {
            n_a++;
        }
        else
        {
            n_b++;
        }
    }

    if(n_a == 0 || n_b == 0)
    {
        cout << "No" << endl;
    }
    else
    {
        cout << "Yes" << endl;
    }

    return 0;
}