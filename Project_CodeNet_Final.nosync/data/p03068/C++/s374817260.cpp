#include<iostream>
#include<string>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, K;
    string S;
    cin >> N >> S >> K;
    for (int i = 0; i < N; i++) {
        if (S[i] == S[K - 1]) cout << S[i];
        else cout << '*';
    }
    cout << endl;
    return 0;
}