#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cmath>
#include <utility>
#include <vector>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;

int main() {
    char x[] = {'a', 'e', 'i', 'o', 'u'};
    char c;
    cin >> c;
    rep(i, 5) {
        if(x[i] == c) {
            cout << "vowel" << endl;
            return 0;
        }
    }

    cout << "consonant";
    
    cout << endl;
    return 0;
}