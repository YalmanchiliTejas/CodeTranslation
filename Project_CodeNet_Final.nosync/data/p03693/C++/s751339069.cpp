#include<bits/stdc++.h>
using namespace std;

int main()
{
    int r, g, b, N;
    cin >> r >> g >> b;

    N = r*100 + g*10 + b;

    if (N%4 == 0)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl; 
    }
    
}