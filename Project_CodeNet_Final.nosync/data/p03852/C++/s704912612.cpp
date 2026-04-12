// Author: Vamsi Krishna Reddy Satti
// With love for Competitive Programming!
 
#include <bits/stdc++.h>
using namespace std;
 
#define fast_io ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define cout_precision cout.setf(ios::fixed); cout.precision(32);
 
using ll = int64_t; using vll = vector<ll>; using vvll = vector<vll>;
using pll = pair<ll, ll>; using vpll = vector<pll>; using vvpll = vector<vpll>;
using ld = long double;
 
// ------------------------------------------------------------------------------------------------

char c;

int main() {
    fast_io; cout_precision;
    cin >> c;
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
        cout << "vowel" << endl;
    } else {
        cout << "consonant" << endl;
    }
}