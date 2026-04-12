#include <iostream>
#include <vector>
#include <algorithm>
#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define REP(i, n) for(int i = 1; i < (int)(n); ++i)
using namespace std;

int main() {
    string S;
    cin >> S;
    if (S[0] == S[1] && S[1] == S[2]) cout << "No\n";
    else cout << "Yes\n";
    return 0;
}
