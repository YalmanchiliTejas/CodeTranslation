#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>
#include <iomanip>
using namespace std;

//#define int long long
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define INF int(1e9)

int main(void) {
    string s;
    cin >> s;
    if(s[0] == 'a' || s[0] == 'i' || s[0] == 'u' || s[0] == 'e' || s[0] == 'o') {
        cout << "vowel\n";
    } else {
        cout << "consonant\n";
    }
    
    return 0;
}