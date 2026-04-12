#include <iostream>

using namespace std;

int main()
{
    char cc;
    cin >> cc;

    if(cc == 'a' || cc == 'o' || cc == 'u' || cc == 'e' || cc == 'i')
        cout << "vowel";
    else
        cout << "consonant";


    return 0;
}
