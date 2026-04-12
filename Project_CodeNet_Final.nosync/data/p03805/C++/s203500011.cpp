#define _USE_MAT_DEFINES
#include<iostream>
#include <iomanip>
#include<stdio.h>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include <queue>
#include <utility>
#include <map>
#include <set>
#include <stack>
#include <deque>
#include <numeric>
#include <functional>
using namespace std;

void dfs(int now,vector<vector<bool>>pass, vector<bool>isVidited,int &ans) {
    int N = pass.size() - 1;
    if (count(isVidited.begin(), isVidited.end(), true) == N) {
        ans++;
        return;
    }
    for (int i = 1; i <= N; i++) {
        if (pass[now][i] == true && isVidited[i] == false) {
            isVidited[i] = true;
            dfs(i, pass, isVidited, ans);
            isVidited[i] = false;
        }
    }
    return;
}


int main() {

    int N, M;
    cin >> N >> M;
    vector<vector<bool>>pass(N + 1, vector<bool>(N + 1, false));
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        pass[a][b] = pass[b][a] = true;
    }

    vector<bool>isVidited(N + 1, false);
    isVidited[1] = true;
    int ans = 0;
    dfs(1, pass, isVidited, ans);

    cout << ans << endl;

    return 0;
}