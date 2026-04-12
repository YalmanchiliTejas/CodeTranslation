#include<iostream>
#include<stdio.h>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include <queue>
#include <utility>
#include <map>
using namespace std;

#define INF 100

int main() {
    int N;
    cin >> N;
    vector<string>S(N);
    vector<vector<int>>count(N+1, vector<int>(26,0));
    for (int i = 0; i < N; i++) {
        cin >> S[i];
    }
    for (int i = 0; i < 26; i++) {
        count[N][i] = INF;
    }

    //文字の個数を数える
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < S[i].size(); j++) {
            count[i][S[i][j] - 'a']++;
        }
    }
    //全ての文書に存在していた文字の種類と個数を数える
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 26; j++) {
            count[N][j] = min(count[N][j], count[i][j]);
        }
    }

    string ans;

    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < count[N][i]; j++) {
            ans.push_back('a' + i);
        }
    }

    cout << ans;
    

    return 0;
}