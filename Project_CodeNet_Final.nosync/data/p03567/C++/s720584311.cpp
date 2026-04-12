#include <bits/stdc++.h>
#define endl '\n';

typedef long long ll;

using namespace std;

const string YES = "Yes";
const string NO  = "No";

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    string s;
    bool flg = false;

    cin >> s;

    for (int i = 0; i < s.size() - 1; ++i) {
        if (s.substr(i, 2) == "AC") {
            flg = true;
            break;
        }
    }

    cout << (flg ? YES : NO) << endl;

    return 0;
}

