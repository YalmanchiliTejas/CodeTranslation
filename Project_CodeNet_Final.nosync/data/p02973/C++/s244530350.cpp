#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#include <iostream>

using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    vector<int> A(N), maxAry(0);
    REP(i, N) { cin >> A.at(i); }
    for (int n : A) {
        if (!maxAry.size()) {
            maxAry.push_back(n);
        } else {
            int left = 0, right = maxAry.size();
            while (left < right) {
                int mid = (left + right) / 2;
                if (maxAry[mid] >= n) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }

            if (left == maxAry.size())
                maxAry.push_back(n);
            else if (n > maxAry[left])
                maxAry[left] = n;
            else
                maxAry[left + 1] = n;
        }
    }
    cout << maxAry.size() << "\n";
}