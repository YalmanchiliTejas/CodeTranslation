#include<bits/stdc++.h>
using namespace std;

string S;

int main()
{
    cin >> S;
    bool aflag = false;
    bool bflag = false;
    for(int i = 0; i < 3; i++)
    {
        if(S[i] == 'A') aflag = true;
        if(S[i] == 'B') bflag = true;
    }
    cout  << ((aflag && bflag) ? "Yes" : "No") << endl;

}