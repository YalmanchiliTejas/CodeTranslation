#include <iostream>
#include <string>

using namespace std;

int main(){
    char c;
    int flag = 0;
    cin >> c;

    if(c=='a'||c=='i'||c=='u'||c=='e'||c=='o') flag++;

    cout << ((flag == 1) ? "vowel" : "consonant") << endl;

    return 0;
}