#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>
#include<vector>
#include<map>
using namespace std;
int main() {
    char c;
    cin >> c;
    if(c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o')
        cout << "vowel" << endl;
    else cout << "consonant" << endl;
    return 0;
}