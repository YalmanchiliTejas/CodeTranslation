#include<bits/stdc++.h>
using namespace std;
int main()
{
    int X,Y,Z;
    cin >> X >> Y >> Z;
    int remain = X % (Y + Z);
    if(remain >= Z)
        cout << X / (Y + Z);
    else    
        cout << X / (Y + Z) - 1;
    cout << '\n';
}
