#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    string s;
    cin >> s;

    vector<int> cnt(2);
    for (int i = 0; i < 3; i++)
        cnt[s[i] - 'A']++;

    if (cnt[0] != 0 && cnt[1] != 0)
        cout << "Yes\n";
    else
        cout << "No\n";

    return 0;
}
