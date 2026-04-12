#include<iostream>
#include<string>
#define MAX_N 55
using namespace std;
typedef long long ll;

bool is_checked[MAX_N];
ll checked_burger[MAX_N], burger_len[MAX_N];
ll X;

ll dfs(int level) {
    if (level == 0) {
        burger_len[level] = 1LL;
        return checked_burger[level] = 1LL;
    }
    else {
        if (is_checked[level]) return checked_burger[level]; 
        else {
            is_checked[level] = true;
            checked_burger[level] = dfs(level - 1) * 2LL + 1LL;
            burger_len[level] = burger_len[level - 1] * 2LL + 3LL;
            return checked_burger[level];
        }
    }
}

ll ddfs(int level, ll length) {
    // levelハンバーガーの1層目からlength層目のパティを数える
    if (level == 0) return 1LL;
    if (length == 1) return 0LL;
    ll sub_len = burger_len[level - 1];
    if (length <= 1LL + sub_len) return ddfs(level - 1, length - 1);
    else if (length == 2LL + sub_len) return checked_burger[level - 1] + 1LL;
    else if (length <= 2LL + sub_len * 2LL) return checked_burger[level - 1] + 1LL + ddfs(level - 1, length - 2LL - burger_len[level - 1]);
    else return checked_burger[level];
}

int main() {
    int N;
    cin >> N >> X;
    ll hoge = dfs(N);
    cout << ddfs(N, X) << endl;
    return 0;
}