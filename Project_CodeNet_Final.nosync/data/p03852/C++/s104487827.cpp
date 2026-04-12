#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <numeric>
#include <math.h>


using namespace std;

int main() {
    char c;
    cin >> c;
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        cout << "vowel" << endl;
    else
        cout << "consonant" << endl;
    return 0;
}