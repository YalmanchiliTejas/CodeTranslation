#include <iostream>
#include <random>
using namespace std;
bool isvowel(char c);
int main()
{
  char c; cin >> c;
    if(isvowel(c))
        cout << "vowel";
    else
        cout << "consonant";
}

bool isvowel(char c)
{
    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        return true;
    else
        return false;
}