#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n;
string s;

bool sub(char c0, char c1) {
    bool f = false;
    vector<char> ans(n, ' ');
    ans[0] = c0;
    ans[1] = c1;
    for (int i=1; i<n; i++) {
        char na;
        if ((ans[i]=='S'&&s[i]=='o')||(ans[i]=='W'&&s[i]=='x'))
            na = ans[i-1]=='S'?'S':'W';
        else
            na = ans[i-1]=='S'?'W':'S';
        if (ans[(i+1)%n] != ' ' && ans[(i+1)%n] != na) {
            f = true;
            break;
        }
        ans[(i+1)%n] = na;
    }

    if (!f) {
        char na;
        if ((ans[0]=='S'&&s[0]=='o')||(ans[0]=='W'&&s[0]=='x'))
            na = ans[n-1]=='S'?'S':'W';
        else
            na = ans[n-1]=='S'?'W':'S';
        if (na == ans[1]) {
            for (auto i : ans) cout << i;
            cout << endl;
        }
        else f = true;
    }
    
    return !f;
}

int main() {
    cin >> n >> s;
    if (sub('S', 'S')) return 0;
    if (sub('S', 'W')) return 0;
    if (sub('W', 'S')) return 0;
    if (sub('W', 'W')) return 0;
    cout << -1 << endl;
}
