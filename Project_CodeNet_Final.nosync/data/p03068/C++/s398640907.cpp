#include <iostream>
using namespace std;

int main() {
    int N, K;
    string S;
    cin >> N ;
    // for (int i = 0; i < N; i++) {
    //     cin  >> S[i];
    // }
    cin >> S;
    cin >> K;
    for (int k = 0; k < N; k++){
        if (S[k] != S[K-1]) S[k] = '*';    // SのK番目と違うなら*にしちゃう
    }

    // for (int j = 0; j < N; j++) {
    //     cout << S[j] << endl;
    // }

    cout << S << endl;
}