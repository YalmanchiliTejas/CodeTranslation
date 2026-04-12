#include<iostream>
#include<string>
using namespace std;

int main()
{
    string s;
    cin >> s ;

    string set[5]={"a","i","u","e","o"};

    for(int i = 0 ; i < 5 ; i++ ){
        string t  = set[i];
        if(s==t) {
            cout << "vowel" << endl;
            return 0;
        }
    }
    cout << "consonant" << endl;
}