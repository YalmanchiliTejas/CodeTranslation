#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define sz size()
#define all(a) a.begin(), a.end()
#define allr(a) a.rbegin(), a.rend()
#define mod 1000000007
#define forn(i, n) for (int i = 0; i < (int) (n); ++i)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    char c;
    cin >> c;
    if(c == 'a' || c == 'e' || c == 'i'|| c == 'o'|| c == 'u'){
        cout << "vowel";
        return 0;
    }
    cout << "consonant";
    return 0;
}