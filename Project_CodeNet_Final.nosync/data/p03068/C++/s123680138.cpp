#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define pi 3.141592653589793
using namespace std;


int main() {
//    cout << setprecision(10);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    string s;
    cin >> n >> s >> k;
    char c = s[k - 1];
    for (char ch : s) {
        cout << (ch == c ? ch : '*');
    }

}