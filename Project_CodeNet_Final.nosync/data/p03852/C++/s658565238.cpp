#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <sstream>
#include <cmath>
#include <math.h>
#include <string>
using namespace std;
          

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    char a;
    cin >> a;
    if ( a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u' ) cout << "vowel\n";
    else cout << "consonant\n";
}

