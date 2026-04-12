#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <utility>
#include <cstdio>
using Int = long long;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
int main()
{
    int N; cin >> N;
    vector<string> S(N); REP(i, N) cin >> S[i];
    vector<int> counter(26, 50);
    for (auto s : S) {
        vector<int> counter2(26, 0);
        for (auto c : s) {
            counter2[c-'a']++;
        }
        REP(i, 26) counter[i] = min(counter[i], counter2[i]);
    }
    REP(i, 26) REP(j, counter[i]) putchar('a' + i);
    putchar('\n');
    return 0;
}