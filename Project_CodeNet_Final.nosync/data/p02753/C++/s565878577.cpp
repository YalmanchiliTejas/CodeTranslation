#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string Yes(bool f) {return (f) ? "Yes" : "No";}
string YES(bool f) {return (f) ? "YES" : "NO";}

int main () {
    string S;
    cin >> S;
    cout << Yes(S != "AAA" && S != "BBB") << endl;
}