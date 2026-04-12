#include <bits/stdc++.h>

using namespace std;

int main()
{   
    
    ios_base::sync_with_stdio(false);
    
    /*Code from here*/
    char c;
    cin >> c;
    
    const string s = "aeiou";
    
    if (find(s.begin(), s.end(), c) != s.end())
        cout << "vowel\n";
    else
        cout << "consonant\n";
    
    return 0;
}