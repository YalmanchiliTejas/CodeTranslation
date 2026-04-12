#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <list>
#include <cmath>
#include <limits>

using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
typedef long long ll;

int main() {
    char c;
    cin >> c;
    if(c == 'a' or c == 'i' or c == 'u' or c == 'e' or c == 'o') cout << "vowel" << endl;
    else cout << "consonant" << endl;
}
