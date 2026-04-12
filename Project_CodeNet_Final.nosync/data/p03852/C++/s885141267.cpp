#include <bits/stdc++.h>
using namespace std;

char c;

int main()
{
    cin>>c;
    string s="aeiou";
    for (int i=0; i<5; i++) {
        if (c==s.at(i)) {
            cout<<"vowel";
            return 0;
        }
    }
    cout<<"consonant";
    return 0;
}
