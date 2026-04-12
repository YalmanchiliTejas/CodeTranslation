#include <bits/stdc++.h>
using namespace std;

int main()
{
    string S;
    cin >> S;

    char c = S[0];
    bool yes = false;
    for(int i=1;i<S.length();++i)
    {
        if(c==S[i])
        {
            continue;
        }
        else
        {
            yes = true;
            break;
        }
    }

    if(yes)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    

}
