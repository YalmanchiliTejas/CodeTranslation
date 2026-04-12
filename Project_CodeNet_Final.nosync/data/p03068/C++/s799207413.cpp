#include<iostream>
using namespace std;
int main() {
    int N,K;
    string S,T="";
    cin >> N >> S >> K;
    for (int i=0; i<N; i++) {
        if (S[i] == S[K-1])
            T += S[i];
        else
            T += '*';
    }
    cout << T << endl;
    return 0;
}
