#include <bits/stdc++.h>
#define ll long long int
#define yorn(f) cout<<((f)?"Yes":"No")<<endl
#define YORN(f) cout<<((f)?"YES":"NO")<<endl
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
int main()
{
    char c;
    cin >> c;
    switch (c) {
        case 'a':
        case 'i':
        case 'u':
        case 'e':
        case 'o':
            cout << "vowel" << endl;
            break;
        default:
            cout << "consonant" << endl;
    }
    return 0;
}