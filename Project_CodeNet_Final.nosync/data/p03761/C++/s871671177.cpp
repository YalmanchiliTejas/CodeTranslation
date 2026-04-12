#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())

void solve(){
    int n;
    cin >> n;

    // for (char i = 'a'; i <= 'z'; i++) {
    //     cout << i << endl;
    // }
    
    vector<map<char, int>> v(n);
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        for (int j = 0; j < (int)s.size(); j++) {
            v[i][s[j]]++;
        }
    }

    vi numalpha(27);
    int idx=0;
    for (char c = 'a'; c <= 'z'; c++) {
        int count=INT_MAX;
        for (int i = 0; i < n; i++) {
            count = min(count, v[i][c]);
        }
        numalpha[idx] = count;
        idx++;
    }

    for (int i = 0; i < 27; i++) {
        // cout << numalpha[i] << endl;
        if (numalpha[i] != 0) {
            for (int j = 0; j < numalpha[i]; j++) {
                cout << (char)('a' + i);
            }
        }
    }
    cout << endl;

    return;
}

int main(int argc, char const* argv[])
{
    solve();
    return 0;
}
