#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define REP(i, FN) for(int (i) = 0; i < (FN); i++)

int main() {
    int n;
    int a[55][26] = {{0}};
    cin >> n;
    REP(i, n){
        string str;
        cin >> str;
        REP(j, str.size()) a[i][str[j] - 'a']++;
    }

    string ans;
    REP(i, 26){
        int mini = a[0][i];
        REP(j, n) mini = min(a[j][i], mini);
        REP(j, mini) ans += i + 'a';
    }
    cout << ans << endl;
    return 0;
}
