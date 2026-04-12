#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int N, K;
string S;

int main() {
    cin >> N >> S >> K;
    string ans = "";

    for (int i = 0; i < N; i++){
        if (S[i] == S[K-1]) ans += S[K-1];
        else ans += '*';
    }
    cout << ans << endl;

}