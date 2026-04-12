#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for( int i = 0; i < (int)(n); i++ )

int main( void )
{
    char c;
    cin >> c;
    string x = "aiueo";
    bool y = false;
    
    rep(i,x.size())
    {
        if ( c == x.at(i) )
        {
            y = true;
        }
    }
    
    if ( y )
        cout << "vowel" << endl;
    else
        cout << "consonant" << endl;
}