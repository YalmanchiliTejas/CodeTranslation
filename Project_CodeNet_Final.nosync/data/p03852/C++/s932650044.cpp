#include <iostream>
using namespace std;
char vowel[6]={'a','e','e','i','o','u'};
int main(){
    char s;
    cin>>s;
    for (int i = 0; i <6 ; ++i) {
        if (s == vowel[i])
        {cout << "vowel";
            return 0;}
    }
    cout<<"consonant";
    return 0;
}