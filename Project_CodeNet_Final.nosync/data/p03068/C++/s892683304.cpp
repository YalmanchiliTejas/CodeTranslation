#include <iostream>
#include <string>

using namespace std;

int main(void) {
    int N;
    string S;
    int K;
    cin >> N >> S >> K;
    char ref = S[K-1];
    for(int i = 0; i < N; i++) {
        if(S[i] != ref) {
            S[i] = '*';
        }
    }
    cout << S << endl;
    return 0;
}