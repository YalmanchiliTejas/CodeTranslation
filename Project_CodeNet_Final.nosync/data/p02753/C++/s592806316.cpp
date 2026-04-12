#include <bits/stdc++.h>
using namespace std;


int main()
{
    string S;
    cin >> S;
    int As = 0;
    int Bs = 0;
    for(int i = 0; i < S.size(); i++)
    {
        if(S[i] == 'A') As++;
        else Bs++;
    }

    if(As >= 1 && Bs >= 1 ) 
    {
        cout << "Yes" << endl;
    }
    else 
    {
        cout << "No" << endl;
    }


    return 0;
}