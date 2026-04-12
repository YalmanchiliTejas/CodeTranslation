#include<bits/stdc++.h>

int main() {
    using namespace std;
    string S;
    cin >> S;
    puts(S[1] == S[0] && S[2] == S[0] ? "No" : "Yes");
    return 0;
}