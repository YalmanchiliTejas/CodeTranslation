#include <bits/stdc++.h>
using namespace std;

int main() {
    unsigned long N, K;
    string S;
    cin >> N >> S >> K;
    auto c = S[K - 1];
    string T;
    transform(S.begin(), S.end(), back_inserter(T), [&c](auto a){return a == c ? c : '*';});
    cout << T << endl;
    return 0;
}