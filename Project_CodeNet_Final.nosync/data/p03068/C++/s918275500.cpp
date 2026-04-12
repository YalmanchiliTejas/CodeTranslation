#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

int main() {
    int N,K;
    string S, ans;
    cin >> N >> S >> K;

    char c = S.at(K-1);

    ans = "";

    for(int i=0; i < S.size(); i++) {
        if(S.at(i) != c) {
            ans += "*";
        } else {
            ans += c;
        }
    }

    cout << ans << endl;

    return 0;
}