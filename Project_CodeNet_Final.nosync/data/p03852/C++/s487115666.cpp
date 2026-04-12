#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main(void)
{
    char s;
    cin >> s;

    if(s == 'a' || s == 'e' || s == 'i' || s == 'o' || s == 'u'  )
        cout << "vowel" << endl;
    else
        cout << "consonant" << endl;

    return 0;
}