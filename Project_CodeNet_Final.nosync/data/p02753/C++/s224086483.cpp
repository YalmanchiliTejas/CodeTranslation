#include<bits/stdc++.h>

using namespace std ;

int main ()
{
    string s ;
    cin >> s ;
    set < char > ans ;
    for ( auto i : s )
    {
        ans.insert(i);
    }
    ans.size() == 2  ? cout << "Yes" : cout << "No" ;
    return 0 ;
}
