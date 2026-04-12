#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define zero_pad(num) setfill('0') << std::right << setw(num)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int main() {
    char c;
    cin >> c;
    cout << ((c=='a'||c=='i'||c=='u'||c=='e'||c=='o')?"vowel":"consonant") << endl;
}