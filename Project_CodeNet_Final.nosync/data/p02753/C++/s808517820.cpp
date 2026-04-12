#include<iostream>
#include<algorithm>
#include<math.h>
#include<vector>
#include<map>
#include<set>

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rrep(i, a, n) for (int i = a; i <= (n); ++i)

using namespace std;
using ll = long long;

int main() {
    string S; cin >> S;

    if ((S[0] == S[1]) && (S[0] == S[2])) cout << "No" << endl;
    else cout << "Yes" << endl;
    return 0;
}
