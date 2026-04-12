#include <bits/stdc++.h>
#define endl '\n';

typedef long long ll;

using namespace std;

const string YES = "YES";
const string NO  = "NO";

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;

    cin >> n;

    if (n == 7 || n == 5 || n == 3) {
        cout << YES;
    } else {
        cout << NO;
    }
    cout << endl;

    return 0;
}

