#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;




int main()
{
    string s="aeiou";
    char c;
    cin>>c;
    for (int i=0;i<s.length();i++)
    {
        if (c==s[i])
        {
            cout<<"vowel"<<endl;return 0;
        }
    }
    cout<<"consonant"<<endl;

}
