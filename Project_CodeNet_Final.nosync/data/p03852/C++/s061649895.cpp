#include <iostream>

using namespace std;

int main()
{
    string x;
    cin >> x;
    if (x=="a" || x=="e" || x=="u" || x=="i" || x=="o"){
        cout << "vowel";
    }else{
        cout << "consonant";
    }
    return 0;
}
