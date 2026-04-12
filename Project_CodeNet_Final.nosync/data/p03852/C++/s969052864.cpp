#include <iostream>

using namespace std;

int main()
{
    char test;
    cin>>test;
    if (test == 'a' || test=='i' || test=='e' || test=='u' || test=='o'){
        cout<< " vowel ";
    }
    else{
        cout<<"consonant";
    }
    return 0;
}
