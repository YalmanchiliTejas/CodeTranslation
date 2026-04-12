#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())

void solve(){
    string s;
    cin >> s;

    // cout << s.substr(0, 2) << endl;
    for (int i = 0; i < s.size(); i++) {
        if (s.substr(i, 2) == "AC") {
            cout << "Yes" << endl;
            return;
        }
    }
    cout << "No" << endl;

    return;
}

int main(int argc, char const* argv[])
{
    solve();
    return 0;
}
