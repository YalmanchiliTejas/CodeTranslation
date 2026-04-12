#include <bits/stdc++.h>
#define endl '\n';

typedef long long ll;

using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    char c;

    cin >> c;

    switch (c) {
        case 'a':
        case 'i':
        case 'u':
        case 'e':
        case 'o':
            cout << "vowel";
            break;
        default:
            cout << "consonant";
            break;
    }
    cout << endl;

    return 0;
}
