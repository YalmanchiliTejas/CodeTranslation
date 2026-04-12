#include <iostream>

using namespace std;

int main()
{
    char vowels[5] = {'a', 'e', 'i', 'o', 'u'};

    char c;
    cin >> c;

    bool prime = false;

    for (int i=0; i<5; i++)
    {
        if (c==vowels[i])
        {
            prime = true;
            break;
        }
    }

    if (prime==true) {cout << "vowel" << endl;}
    else {cout << "consonant" << endl;}
    return 0;
}