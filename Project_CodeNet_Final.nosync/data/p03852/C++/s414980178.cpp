#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
#define INF 1010101010
#define MOD 1000000007

int N, K;

int main() {
    char c;
    cin >> c;
    for (const char &v: "aiueo") 
        if (c == v) {
            cout << "vowel" << endl;
            return 0;
        }
    cout << "consonant" << endl;
}