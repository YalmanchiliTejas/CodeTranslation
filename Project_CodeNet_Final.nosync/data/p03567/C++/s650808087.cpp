#include <bits/stdc++.h>
using namespace std;

string s;

int main() 
{
    cin>>s; bool b = false; 
    for( int i = 0; i < s.length()-1; i ++ ) 
        if( s[i] == 'A' && s[i+1] == 'C' ) b = true;

    puts( b ? "Yes" : "No" ); 

    return 0;
}