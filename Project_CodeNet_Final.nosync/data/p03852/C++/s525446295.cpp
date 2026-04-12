#include <iostream>
using namespace std;
int main() {
    char c;
    int voule,capital_voule;
    cin >> c;
    voule = (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    capital_voule = (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
    if (voule||capital_voule){
        cout <<"vowel";
    }else{
        cout<<"consonant";
    }
    return 0;
}