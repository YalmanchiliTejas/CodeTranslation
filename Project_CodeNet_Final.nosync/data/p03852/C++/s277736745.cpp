#include<iostream>
#include<string>
#include<algorithm>
#include<cstdlib>
using namespace std;


int main() {
    char a;
    cin >> a;
    if (a == 'a' || a == 'i' || a == 'e' || a == 'u' || a == 'o')cout << "vowel" << endl;
    else cout << "consonant" << endl;
    return 0;
}