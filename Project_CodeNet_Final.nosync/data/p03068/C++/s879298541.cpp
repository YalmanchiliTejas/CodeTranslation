#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N, K; string S; cin >> N >> S >> K;
    char a = S[K-1];
    for (char c : S) {
        cout << (c == a ? c : '*');
    }
    cout << '\n';
    return 0;
}
