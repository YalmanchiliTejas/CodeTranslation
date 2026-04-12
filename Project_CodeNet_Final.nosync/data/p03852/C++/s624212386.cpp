#include <iostream>
#include<string>
using namespace std;

int main()
{

string n;cin>>n;
string vowels="aeiou";
int loc=vowels.find(n);
if(loc==-1)
{
    cout<<"consonant";
}else
{
    cout<<"vowel";
}
    return 0;
}
