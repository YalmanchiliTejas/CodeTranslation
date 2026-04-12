#include<bits/stdc++.h>
using namespace std;

int main()
{
    string ss;
    cin >> ss;
    int ca=0;
    for(int i=0;i<3;i++)
    {
        if(ss[i]=='A')  ca++;
    }
    if(ca==0)   cout << "No\n";
    else if(ca==3)  cout << "No\n";
    else    cout << "Yes\n";
    return 0;
}