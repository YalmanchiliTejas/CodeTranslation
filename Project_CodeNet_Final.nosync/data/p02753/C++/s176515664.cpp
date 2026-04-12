#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

int main()
{
    string s;
    cin >> s;
    int a(0), b(0) ;
    rep(i,3)
    {
        if(s.at(i)=='A')
        {
            a++;
        }
        else
        {
            b++ ;
        }
        
    }
    if(a&&b)
    {
        cout << "Yes" << endl ;
    }
    else
    {
        cout << "No" << endl ;
    }
    
}