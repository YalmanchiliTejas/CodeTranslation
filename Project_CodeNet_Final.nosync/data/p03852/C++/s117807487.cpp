
#include <iostream>

using namespace std;

int main()
{

char c;
cin>>c;

bool vowel=(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');

if(vowel)
    cout<<"vowel"<<endl;
else
    cout<<"consonant"<<endl;
    return 0;
    }