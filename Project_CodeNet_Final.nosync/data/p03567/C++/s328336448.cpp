#include <iostream>
using namespace std;
int main() {
    string S; cin >> S;
    int N = S.length();
    for (int i = 0; i < N - 1; i++) {
        if (S[i] == 'A' && S[i + 1] == 'C') {
            printf("%s\n", "Yes");
            return 0;
        }
    }
    printf("%s\n", "No");
    return 0;
}