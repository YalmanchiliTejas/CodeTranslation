#include <bits/stdc++.h>

using namespace std ;

int main ()
{
    string s ;
    bool A_exists = 0 , B_exists = 0 ; // we declare two boolean variables to check weather the letters "A" and "B" exist

    cin >> s ;

    for ( int i = 0 ; i < s.size() ; i++ )
    {
        if ( s[i] == 'A' )          A_exists = true ; // once we find the letter "A" we assign the variable A_exists with value true
        else if ( s[i] == 'B' )     B_exists = true ; // same for letter B
    }

    if ( A_exists && B_exists )     cout << "Yes" ; // if letter "A" and letter "B" exist the answer is Yes
    else                            cout << "No" ; // otherwise answer is No

}
