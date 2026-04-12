/**
 *    author: apurba_debnath
**/
#include <bits/stdc++.h>


#define ll long long
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;


using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    int a = 0, b = 0;
    cin >> s;
    for (char ch : s) {
        if (ch == 'A')
            a++;
        else
            b++;
    }
    if (a > 0 && b > 0)
        cout << "Yes";
    else
        cout << "No";

    return 0;
}
