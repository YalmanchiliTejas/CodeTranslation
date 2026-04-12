#include <iostream>
#include <vector>
using namespace std;

int main(void){
    char c;
    cin >>c;
    if(c=='a'||c=='i'||c=='u'||c=='e'||c=='o'){
        cout << "vowel";
        return 0;
    }
    else{
        cout << "consonant";
        return 0;
    }
    return 0;
}