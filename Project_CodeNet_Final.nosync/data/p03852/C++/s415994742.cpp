#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < (n); i++)
#define ALL(a) a.begin(), a.end()
#define RALL(a) a.rbegin(), a.rend()
using namespace std;
using ll = long long;
const ll MOD = 1000000007;
const ll INF = MOD * MOD;

int main() {

    char c;
    cin >> c;

    cout << (c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o' ? "vowel" : "consonant") << endl;
    
    return 0;
}