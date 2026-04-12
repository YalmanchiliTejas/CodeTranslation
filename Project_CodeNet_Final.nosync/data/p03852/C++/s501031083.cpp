#include <bits/stdc++.h>
using namespace std;

int main() {
    char N;
    cin >> N;

    string ans = "consonant";

    if (N == 'a' || N == 'e' || N == 'i' || N == 'o' || N == 'u') {
        ans = "vowel";
    }

    cout << ans << endl;

    return 0;
}
