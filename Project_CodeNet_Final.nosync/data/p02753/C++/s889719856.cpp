#include <bits/stdc++.h>
using namespace std;

int main() {
    string S;
    cin >> S;

    puts(S.find('A') != -1 and S.find('B') != -1 ? "Yes" : "No");
}