#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    string S;
    int K;

    // in
    cin >> N;
    cin >> S;
    cin >> K;

    // calc
    char c = S[K-1];
    for(int i=0; i<N; i++){
        if (S[i]!=c) S[i]='*';
    }

    // out
    cout << S << endl;
    return 0;
}