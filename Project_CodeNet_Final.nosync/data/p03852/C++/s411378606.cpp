#include<iostream>

using namespace std;

int main()
{
    char letter;

    cin >> letter;

    if(letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' || letter == 'u')
    {
        cout << "vowel" << endl;
    }
    else {
       cout << "consonant" << endl;
    }

    return 0;
}
