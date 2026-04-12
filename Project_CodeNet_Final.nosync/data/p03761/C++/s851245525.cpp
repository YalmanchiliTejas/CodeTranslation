#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include<algorithm>
#include<string>
#include <map>
#include <queue>
#include <stack>
#include<set>

#define DIV 998244353

using namespace std;
using ll = long long;
using ldb = long double;

int main() {
    int n; cin >> n;
    vector<string> s(n);
    for (int i = 0; i < n; i++)
        cin >> s[i];
    vector<vector<int>> alp(n, vector<int>(26));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < s[i].size(); j++)
            alp[i][s[i][j] - 'a']++;
    }

    for (int i = 0; i < 26; i++) {
        int cnt = 1e5;
        for (int j = 0; j < n; j++) {
            cnt = min(cnt, alp[j][i]);
        }
        for (int k = 0; k < cnt; k++)
            //cout << i + 'a';
            printf("%c", i + 'a');
    }
    cout << endl;
}
