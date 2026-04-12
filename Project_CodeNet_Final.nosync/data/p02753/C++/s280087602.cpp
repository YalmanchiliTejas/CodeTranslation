#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    string s;

    cin >> s;

    bool a_flg = false, b_flg = false;
    for(int i=0; i<s.size(); i++)
    {
        if(s[i] == 'A')
        {
            a_flg = true;
        }
        else
        {
            b_flg = true;
        }
        
    }

    if((a_flg) && (b_flg) )
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    
    return 0;
}