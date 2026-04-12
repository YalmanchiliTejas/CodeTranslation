#include<bits/stdc++.h>
using namespace std;
#define Mod(n) n % 1000000007
int main()
{
    int X,Y,Z;
    cin >> X >> Y >> Z;
    int num = 0;
    for(int i = 1;i < X;i++)
    {
        if(X >= Y * i + Z * i + Z)
            num = i;
        else
            break;
    }
    cout << num << '\n';
}

