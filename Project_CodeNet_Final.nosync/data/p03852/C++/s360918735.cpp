#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()

int main()
{
    char c;
    cin >> c;

    string s = "aiueo";

    cout << (s.find(c) == -1 ? "consonant" : "vowel") << '\n';
    return 0;
}
