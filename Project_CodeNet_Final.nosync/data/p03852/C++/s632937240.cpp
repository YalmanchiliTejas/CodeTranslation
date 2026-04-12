#include <iostream>

using namespace std;

bool isVowel(char c)
{
    if(c=='a'|| c=='e'||c=='i'||c=='o'||c=='u')
        return true ;
    else
        return false ;
}
int main()
{
    char c ;

    cin>> c ;
    if (isVowel(c))
        cout<< "vowel" ;
    else
        cout << "consonant" ;
    return 0;
}
