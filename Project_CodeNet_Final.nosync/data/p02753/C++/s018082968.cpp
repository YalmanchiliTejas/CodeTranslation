#include<bits/stdc++.h>
using namespace std;
string s;
int i;
bool cond = false;
int main()
{
    cin >> s;
    for(i=1;i<3;i++)
    {
        if(s[i]!=s[i-1])
            cond = true;
    }
    if(cond)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}
