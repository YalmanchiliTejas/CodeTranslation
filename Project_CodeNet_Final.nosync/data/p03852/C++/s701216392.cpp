#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)

int main()
{
    string ans = "consonant";
    char c;
    cin >> c;
    if (c == 'a' || c == 'i' || c == 'u' || c == 'o' || c == 'e' ){
        ans = "vowel";
    }
    cout << ans << "\n";
    return 0;
}
