#include <bits/stdc++.h>
using namespace std;

int main() {
    unsigned long N, K;
    string S;
    cin >> N >> S >> K;
    auto c = S[K - 1];
    for(auto& a : S)if(a != c)a = '*';
    cout << S << endl;
    return 0;
}