#include<iostream>
#include<string>
using namespace std;

int main()
{
    int cntA = 0, cntB = 0;
    string s;
    cin >> s;
    
    for(int i = 0; i < 3; i++)
    {
        if(s[i] == 'A')
            cntA = 1;
        if(s[i] == 'B')
            cntB = 1;
    }
    
    if(cntA && cntB)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    
    return 0;
}
