#include <bits/stdc++.h>
using namespace std;

//Function Macros:
#define rep(i, n) for(int(i) = 0; (i) < (n); (i)++)
#define all(v) (v).begin(), (v).end()
#define setpre(n) cout << fixed << setprecision(n)

//Type / Class / Struct Definitions:
using ll = long long;
using ull = unsigned long long;

//Constants:
const int INF = 2e9;
const int MOD = 1e9 + 7;

//Global Variables:

//Prototype Declarations:
int gcd(int, int);

//================ Main Loop ================
int main() {
    string s;
    cin >> s;
    if(s[0] == s[1] && s[1] == s[2]) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
    }
    return 0;
}
//===========================================

//Functions:
int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}