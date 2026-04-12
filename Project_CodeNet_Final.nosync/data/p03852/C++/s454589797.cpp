#include<iostream>
#include<string>
#include <numeric>
using namespace std;
int a, b, c;
char s;
int main() {
    cin >> s;
    if(s=='a'||s=='i'||s=='u'||s=='e'||s=='o') cout << "vowel" << endl;
    else cout <<"consonant" << endl;
    return 0;
}