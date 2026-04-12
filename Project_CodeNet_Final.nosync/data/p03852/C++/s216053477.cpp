#include <iostream>

using namespace std;

int main()
{
    int l=0,i;
    char c;
    cin>>c;
    string s="aeiou";
    for(i=0;i<5;i++){
        if(c==s[i])
           l=9;
    }
    if(l==9)
       cout<<"vowel";
    else
        cout<<"consonant";
}
