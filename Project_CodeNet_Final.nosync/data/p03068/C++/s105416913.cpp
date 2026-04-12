#include <iostream>
using namespace std;

int main() {
    int K = 0; int N = 0;
    cin >> N;
    string S;
    cin >> S;
    cin >> K;

    int s_size = N;

    char s = S[K-1];

    for(int i = 0; i < s_size; i++) {
        if(S[i] != s) S[i] = '*';
    }

    cout << S << endl;
}
