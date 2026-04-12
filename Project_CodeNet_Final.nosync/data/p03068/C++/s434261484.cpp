#include <iostream>
#include <string>
#include <regex>
using namespace std;

int main() {
    int N, K;
    string S, T;
    cin >> N >> S >> K;
    T = S.substr(K - 1, 1);
    cout << regex_replace(S, regex("[^" + T + "]"), "*") << endl;
}