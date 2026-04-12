#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (n); ++i)

typedef long long ll;
typedef pair<int, int> P;

const int MAX = 1e5 + 5;
const int INF = 1001001001;
const int MOD = 1e9 + 7;

int main(){
    string s;
    cin >> s;

    bool ans = s[0] != s[1] || s[1] != s[2];

    if (ans) puts("Yes");
    else puts("No");
}