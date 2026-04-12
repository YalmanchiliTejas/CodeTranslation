#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <utility>
#include <iomanip>
#include <cmath>
#include <bitset>
#include <string>
#define REP(i,n) for(int i=0;i<n;i++)
using Int = long long;
using namespace std;
int main()
{
    char c; cin >> c;
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
        cout << "vowel" << endl;
    } else {
        cout << "consonant" << endl;
    }
    return 0;
}