#include <bits/stdc++.h>
using namespace std;

#define     F       first
#define     S       second
typedef pair<int, int>  pi;
typedef long long       ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;

    int cnt1=0, cnt2=0;
    for (int i=0; i<s.size(); ++i) {
        if (s[i]=='A') {
            ++cnt1;
        }
        else {
            ++cnt2;
        }
    }

    if (cnt1 && cnt2) {
        cout << "Yes";
    }
    else {
        cout << "No";
    }

    return 0;
}
